# $NetBSD: check-perms.mk,v 1.3 2006/11/02 02:44:17 rillig Exp $
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

CHECK_PERMS_SKIP?=		# none

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

.PHONY: check-perms
check-perms:
	@${STEP_MSG} "Checking file permissions in ${PKGNAME}"
	${_PKG_SILENT}${_PKG_DEBUG} set -eu;				\
	${PKG_INFO} -qe "checkperms>=1.1"				\
	|| {								\
		${WARNING_MSG} "[check-perms.mk] Skipping file permissions check."; \
		${WARNING_MSG} "[check-perms.mk] Install sysutils/checkperms to enable this check."; \
		exit 0;							\
	};								\
	${PKG_FILELIST_CMD}						\
	| sort								\
	| sed -e 's,\\,\\\\,g'						\
	| while read file; do						\
		case "$$file" in					\
		${CHECK_PERMS_SKIP:@p@${PREFIX}/${p}|${p}) continue ;;@}\
		*) ;;							\
		esac;							\
		printf "%s\\n" "$$file";				\
	  done								\
	| awk ${_CHECK_PERMS_GETDIRS_AWK:Q}				\
	| ${_CHECK_PERMS_CMD} -c
