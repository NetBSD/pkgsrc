# $NetBSD: check-stripped.mk,v 1.5 2013/05/12 06:17:50 obache Exp $
#
# This file checks that after installation, all binaries conform to the
# setting of INSTALL_UNSTRIPPED.
#
# User-settable variables:
#
# CHECK_STRIPPED
#	Whether this check should be enabled or not.
#
#	Default value: "no".
#
# Package-settable variables:
#
# CHECK_STRIPPED_SKIP
#	The list of file patterns that are skipped by the check.
#
#	Default value: (empty)
#
#	Example: bin/* sbin/foo
#

.if defined(PKG_DEVELOPER) && ${PKG_DEVELOPER} != "no"
CHECK_STRIPPED?=		no	# XXX: change to "yes" later
.else
CHECK_STRIPPED?=		no
.endif
CHECK_STRIPPED_SKIP?=		# empty

_CHECK_STRIPPED_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST}

.if !empty(CHECK_STRIPPED:M[Yy][Ee][Ss])
privileged-install-hook: _check-stripped
.  if empty(USE_TOOLS:Mfile)
USE_TOOLS+=	file
.  endif
.endif

_check-stripped: error-check .PHONY
	@${STEP_MSG} "Checking whether binaries are ${_INSTALL_UNSTRIPPED:Dun:U}stripped."
	${RUN} cd ${DESTDIR}${PREFIX};					\
	want_stripped=${_INSTALL_UNSTRIPPED:Dno:Uyes};			\
	${_CHECK_STRIPPED_FILELIST_CMD} | ${SORT} | ${SED} 's,\\,\\\\,g'\
	| while read file; do						\
		case "$$file" in					\
		${CHECK_STRIPPED_SKIP:@p@${p}) continue ;;@}		\
		*) ;;							\
		esac;							\
		dpfile=${DESTDIR}${PREFIX}/$$file;			\
		test -x "$$dpfile" || continue;				\
		if [ ! -r "$$dpfile" ]; then				\
			${DELAYED_WARNING_MSG} "[check-stripped.mk] File \"$$dpfile\" cannot be read."; \
			continue;					\
		fi;							\
		ftype=`LC_ALL=C ${FILE_CMD} $$dpfile`;			\
		case $$want_stripped,$$ftype in				\
		yes,*:*\ ELF\ *,\ not\ stripped*) ${DELAYED_ERROR_MSG} "[check-stripped.mk] $$dpfile should be stripped, but is not.";; \
		no,*:*\ ELF\ *,\ stripped*) ${DELAYED_ERROR_MSG} "[check-stripped.mk] $$dpfile should NOT be stripped, but it is.";; \
		no,*:*\ ELF\ *,\ not\ stripped*) : ${INFO_MSG} "[check-stripped.mk] $$dpfile is not stripped (ok).";; \
		yes,*:*\ ELF\ *,\ stripped*) : ${INFO_MSG} "[check-stripped.mk] $$dpfile is stripped (ok).";; \
		esac;							\
	done
