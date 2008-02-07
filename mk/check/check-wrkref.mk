# $NetBSD: check-wrkref.mk,v 1.16 2008/02/07 21:36:13 rillig Exp $
#
# This file checks that the installed files don't contain any strings
# that point to the directory where the package had been built, to make
# sure that the package still works after the source code has been
# cleaned up.
#
# User-settable variables:
#
# CHECK_WRKREF:
#	The list of directory names that must not appear in installed files.
#
#	* "tools" for the tool wrapper directory
#	* "wrksrc" for WRKSRC
#	* "work" for WRKDIR
#	* "wrkobjdir" for WRKOBJDIR
#	* "pkgsrc" for PKGSRCDIR
#	* "extra" for CHECK_WRKREF_EXTRA_DIRS
#
#	Default value: "tools" for PKG_DEVELOPERs, "no" otherwise.
#
# CHECK_WRKREF_EXTRA_DIRS
#	A list of additional directories (or other strings) that must
#	not appear in the installed files. For pbulk builds, the
#	location where the pbulk tools are installed should be added
#	here.
#
# Package-settable variables:
#
# CHECK_WRKREF_SKIP:
#	The list of filename patterns that should be excluded from this
#	test, either absolute or relative to PREFIX.
#

_VARGROUPS+=			check-wrkref
_USER_VARS.check-wrkref=	CHECK_WRKREF
_PKG_VARS.check-wrkref=		CHECK_WRKREF_SKIP

.if defined(PKG_DEVELOPER)
CHECK_WRKREF?=		tools
.endif
CHECK_WRKREF?=		no
CHECK_WRKREF_SKIP?=	# none

_CHECK_WRKREF_FILELIST_CMD?=	${PKG_FILELIST_CMD}

_CHECK_WRKREF_DIR.no=		# none
_CHECK_WRKREF_DIR.work=		${WRKDIR}
_CHECK_WRKREF_DIR.tools=	${TOOLS_DIR}
_CHECK_WRKREF_DIR.wrkobjdir=	${WRKOBJDIR}
_CHECK_WRKREF_DIR.wrksrc=	${WRKSRC}
_CHECK_WRKREF_DIR.pkgsrc=	${PKGSRCDIR}
_CHECK_WRKREF_DIR.extra=	${CHECK_WRKREF_EXTRA_DIRS}

_CHECK_WRKREF_DIRS=	# none
.for d in ${CHECK_WRKREF}
.  if !defined(_CHECK_WRKREF_DIR.${d})
PKG_FAIL_REASON+=	"[check-wrkref.mk] Invalid value "${d:Q}" for CHECK_WRKREF."
PKG_FAIL_REASON+=	"[check-wrkref.mk] Try one of { tools wrksrc work objwrkdir } instead."
.  else
_CHECK_WRKREF_DIRS+=	${_CHECK_WRKREF_DIR.${d}}
.  endif
.endfor

.if empty(CHECK_WRKREF:M[nN][oO]) && !empty(_CHECK_WRKREF_DIRS:M*)
privileged-install-hook: _check-wrkref
.endif

_check-wrkref: error-check .PHONY
	@${STEP_MSG} "Checking for work-directory references in ${PKGNAME}"
	${RUN} rm -f ${ERROR_DIR}/${.TARGET}
	${RUN}					\
	exec 1>${ERROR_DIR}/${.TARGET};					\
	cd ${DESTDIR}${PREFIX};						\
	${_CHECK_WRKREF_FILELIST_CMD} | ${SORT} |			\
	while read file; do						\
		case "$$file" in					\
		${CHECK_WRKREF_SKIP:@p@${p} | ${PREFIX}/${p}) continue;; @} \
		*) ;;							\
		esac;							\
		${SHCOMMENT} "[$$file]";				\
		for d in ${_CHECK_WRKREF_DIRS}; do			\
			grep "$$d" "$$file" 2>/dev/null |		\
			sed -e "s|^|$$file:	|";			\
		done;							\
	done
	${RUN}								\
	exec 1>>${ERROR_DIR}/${.TARGET};				\
	if ${_NONZERO_FILESIZE_P} ${ERROR_DIR}/${.TARGET}; then		\
		${ECHO} "*** The above files still have references to the build directory."; \
		${ECHO} "    This is possibly an error that should be fixed by unwrapping"; \
		${ECHO} "    the files or adding missing tools to the package makefile!"; \
	fi
