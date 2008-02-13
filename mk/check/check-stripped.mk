# $NetBSD: check-stripped.mk,v 1.1 2008/02/13 15:02:20 rillig Exp $
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

.if defined(PKG_DEVELOPER)
CHECK_STRIPPED?=		no	# XXX: change to "yes" later
.else
CHECK_STRIPPED?=		no
.endif
CHECK_STRIPPED_SKIP?=		# empty

_CHECK_STRIPPED_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST}

.if !empty(CHECK_STRIPPED:M[Yy][Ee][Ss])
privileged-install-hook: _check-stripped
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
		test -x "$$file" || continue;				\
		if [ ! -r "$$file" ]; then				\
			${DELAYED_WARNING_MSG} "[check-stripped.mk] File \"${DESTDIR}${PREFIX}/$$file\" cannot be read."; \
			continue;					\
		fi;							\
		ftype=`LANG=C LC_ALL=C ${FILE_CMD} ./$$file`;		\
		case $$want_stripped,$$ftype in				\
		yes,*:*\ ELF\ *,\ not\ stripped*) ${DELAYED_ERROR_MSG} "[check-stripped.mk] ${DESTDIR}${PREFIX}/$$file should be stripped, but is not.";; \
		no,*:*\ ELF\ *,\ stripped*) ${DELAYED_ERROR_MSG} "[check-stripped.mk] ${DESTDIR}${PREFIX}/$$file should NOT be stripped, but it is.";; \
		no,*:*\ ELF\ *,\ not\ stripped*) ${INFO_MSG} "[check-stripped.mk] ${DESTDIR}${PREFIX}/$$file is not stripped (ok).";; \
		yes,*:*\ ELF\ *,\ stripped*) ${INFO_MSG} "[check-stripped.mk] ${DESTDIR}${PREFIX}/$$file is stripped (ok).";; \
		esac;							\
	done
