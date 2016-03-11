# $NetBSD: check-interpreter.mk,v 1.31 2016/03/11 21:11:47 dholland Exp $
#
# This file checks that after installation, all files of the package
# that start with a "#!" line will find their interpreter. Files that
# have a "#!" line with a non-existent interpreter will generate an
# error message if they are executable, and a warning message otherwise.
#
# Files are not allowed to use /bin/env or /usr/bin/env as an interpreter
# due the use dynamic paths and package developers not checking that they work.
# A classic example is: #!/usr/bin/env python
#
# User-settable variables:
#
# CHECK_INTERPRETER
#	Whether this check should be enabled or not.
#
#	Default value: "yes" for PKG_DEVELOPER, "no" otherwise.
#
# Package-settable variables:
#
# CHECK_INTERPRETER_SKIP
#	The list of file patterns that are skipped by the check.
#	All files in share/examples and share/doc are skipped as well.
#
#	Default value: (empty)
#
#	Example: share/package1/* share/package2/somefile
#

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_INTERPRETER?=		yes
.else
CHECK_INTERPRETER?=		no
.endif
CHECK_INTERPRETER_SKIP?=	# empty

_CHECK_INTERP_SKIP=		share/doc/*
_CHECK_INTERP_SKIP+=		share/examples/*
_CHECK_INTERP_SKIP+=		${CHECK_INTERPRETER_SKIP}

_CHECK_INTERP_FILELIST_CMD?=	${SED} -e '/^@/d' ${PLIST}

.if !empty(CHECK_INTERPRETER:M[Yy][Ee][Ss])
privileged-install-hook: _check-interpreter
.endif

_check-interpreter: error-check .PHONY
	@${STEP_MSG} "Checking for non-existent script interpreters in ${PKGNAME}"
	${RUN} cd ${DESTDIR}${PREFIX};					\
	${_CHECK_INTERP_FILELIST_CMD} | ${SORT} | ${SED} 's,\\,\\\\,g' |\
	while read file; do						\
		case "$$file" in					\
		${_CHECK_INTERP_SKIP:@p@${p}) continue ;;@}		\
		*) ;;							\
		esac;							\
		if [ ! -x "$$file" ]; then				\
			continue;					\
		fi;							\
		if [ -d "$$file" ]; then				\
			continue;					\
		fi;							\
		if [ ! -r "$$file" ]; then				\
			${DELAYED_WARNING_MSG} "[check-interpreter.mk] File \"${DESTDIR}${PREFIX}/$$file\" cannot be read."; \
			continue;					\
		fi;							\
		${SHCOMMENT} "[$$file]";				\
		interp=`LC_ALL=C ${SED} -n -e '1s/^#![[:space:]]*\([^[:space:]]*\).*/\1/p' -e '1q' < "$$file"` \
		|| {	${DELAYED_WARNING_MSG} "[check-interpreter.mk] sed(1) failed for \"${DESTDIR}${PREFIX}/$$file\"."; \
			continue;					\
		};							\
		case "$$interp" in					\
		"") continue;;						\
		/bin/env|/usr/bin/env) if [ -x "$$file" ]; then		\
				${DELAYED_ERROR_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"${DESTDIR}${PREFIX}/$$file\" is not allowed."; \
			else						\
				${DELAYED_WARNING_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"${DESTDIR}${PREFIX}/$$file\" is not allowed."; \
			fi;						\
			continue;;					\
		esac;							\
		if { [ ! -f ${DESTDIR:Q}"$$interp" ] &&			\
		     [ ! -f "$$interp" ]; }; then			\
			${DELAYED_ERROR_MSG} "[check-interpreter.mk] The interpreter \"$$interp\" of \"${DESTDIR}${PREFIX}/$$file\" does not exist."; \
		fi;							\
	done
