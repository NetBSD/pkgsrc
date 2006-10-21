# $NetBSD: check-perms.mk,v 1.2 2006/10/21 11:13:10 rillig Exp $
#
# This file checks that after installation of a package, all files and
# directories of that package have sensible permissions set.
#
# User-settable variables:
#
# CHECK_PERMS: YesNo (default: yes for PKG_DEVELOPER, no otherwise)
#	Specifies whether the permissions check should be run at all.
#
# Package-settable variables:
#
# CHECK_PERMS_SKIP: List of PathMask (default: empty)
#	A list of patterns (like man/*) that should be excluded from the
#	check. Note that a * in a pattern also matches a slash in a
#	pathname.
#

.if defined(PKG_DEVELOPER)
CHECK_PERMS?=		yes
.else
CHECK_PERMS?=		no
.endif

#.if !empty(CHECK_PERMS:M[Yy][Ee][Ss])
#_POST_INSTALL_CHECKS+=	check-perms
#.endif

_CHECK_PERMS_CMD=	${LOCALBASE}/bin/checkperms
_CHECK_PERMS_GETDIRS_AWK=						\
	/.*/ {								\
		print $$0;						\
		dir = $$0;						\
		while (sub("/[^/]*$$", "", dir) && dir != "") {		\
			if (!(dir in dirs)) {				\
				dirs[dir] = "done";			\
				print dir;				\
			}						\
		}							\
	}

CHECK_PERMS_SKIP?=		# none
_CHECK_PERMS_SKIP_FILTER=	case "$$file" in
_CHECK_PERMS_SKIP_FILTER+=	${CHECK_PERMS_SKIP:@.pattern.@${PREFIX}/${.pattern.}|${.pattern.}) continue ;;@}
_CHECK_PERMS_SKIP_FILTER+=	*) ;;
_CHECK_PERMS_SKIP_FILTER+=	esac

.PHONY: check-perms
check-perms:
	@${STEP_MSG} "Checking file permissions in ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG} set -eu;				\
	if [ ! -x ${_CHECK_PERMS_CMD:Q}"" ]; then			\
		${WARNING_MSG} "[check-perms.mk] Skipping file permissions check."; \
		${WARNING_MSG} "[check-perms.mk] Install sysutils/checkperms to enable this check."; \
		exit 0;							\
	fi;								\
	${PKG_FILELIST_CMD}						\
	| sort								\
	| sed -e 's,\\,\\\\,g'						\
	| while read file; do						\
		${_CHECK_PERMS_SKIP_FILTER};				\
		printf "%s\\n" "$$file";				\
	  done								\
	| awk ${_CHECK_PERMS_GETDIRS_AWK:Q}				\
	| ${_CHECK_PERMS_CMD}
