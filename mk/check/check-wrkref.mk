# $NetBSD: check-wrkref.mk,v 1.25 2020/04/26 14:23:25 rillig Exp $
#
# This file checks that the installed files don't contain any strings
# that point to the directory where the package had been built, to make
# sure that the package still works after the source code has been
# cleaned up.
#
# User-settable variables:
#
# CHECK_WRKREF
#	The list of directory names that must not appear in installed files.
#
#	* "tools" for the tool wrapper directory
#	* "wrappers" for the wrappers directory
#	* "home" for FAKEHOMEDIR
#	* "wrksrc" for WRKSRC
#	* "work" for WRKDIR
#	* "wrkobjdir" for WRKOBJDIR
#	* "pkgsrc" for PKGSRCDIR
#	* "buildlink" for BUILDLINK_DIR and BUILDLINK_X11_DIR
#	* "extra" for CHECK_WRKREF_EXTRA_DIRS
#
#	Default value: "tools home" for PKG_DEVELOPERs, "no" otherwise.
#	The "buildlink" option works best in combination with
#	STRIP_DEBUG=yes.
#
# CHECK_WRKREF_EXTRA_DIRS
#	A list of additional directories (or other strings) that must
#	not appear in the installed files. For pbulk builds, the
#	location where the pbulk tools are installed should be added
#	here.
#
# Package-settable variables:
#
# CHECK_WRKREF_SKIP
#	The list of filename patterns that should be excluded from this
#	test, either absolute or relative to PREFIX.
#

_VARGROUPS+=			check-wrkref
_USER_VARS.check-wrkref=	CHECK_WRKREF CHECK_WRKREF_EXTRA_DIRS
_PKG_VARS.check-wrkref=		CHECK_WRKREF_SKIP

.if ${PKG_DEVELOPER:Uno} != "no"
CHECK_WRKREF?=		tools home
.else
CHECK_WRKREF?=		no
.endif
CHECK_WRKREF_SKIP?=	# none

_CHECK_WRKREF_FILELIST_CMD?=	${PKG_FILELIST_CMD}

_CHECK_WRKREF_DIR.no=		# none
_CHECK_WRKREF_DIR.work=		${WRKDIR}
_CHECK_WRKREF_DIR.tools=	${TOOLS_DIR}
_CHECK_WRKREF_DIR.wrappers=	${WRAPPER_DIR}
_CHECK_WRKREF_DIR.home=		${FAKEHOMEDIR}
_CHECK_WRKREF_DIR.wrkobjdir=	${WRKOBJDIR}
_CHECK_WRKREF_DIR.wrksrc=	${WRKSRC}
_CHECK_WRKREF_DIR.pkgsrc=	${PKGSRCDIR}
_CHECK_WRKREF_DIR.buildlink=	${BUILDLINK_DIR}
.if defined(USE_X11) && ${X11_TYPE} != "modular"
_CHECK_WRKREF_DIR.buildlink+=	${BUILDLINK_X11_DIR}
.endif
_CHECK_WRKREF_DIR.extra=	${CHECK_WRKREF_EXTRA_DIRS}

_CHECK_WRKREF_DIRS=	# none
.for d in ${CHECK_WRKREF}
.  if !defined(_CHECK_WRKREF_DIR.${d})
PKG_FAIL_REASON+=	"[check-wrkref.mk] Invalid value \"${d:Q}\" for CHECK_WRKREF."
PKG_FAIL_REASON+=	"[check-wrkref.mk] Valid options are:"
.    for refvar in work tools wrappers home wrkobjdir wrksrc pkgsrc buildlink extra
PKG_FAIL_REASON+=	"[check-wrkref.mk]	${refvar}"
.    endfor
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
	${_CHECK_WRKREF_FILELIST_CMD} | ${SORT} |			\
	while read file; do						\
		case "$$file" in					\
		${CHECK_WRKREF_SKIP:@p@${p} | ${PREFIX}/${p}) continue;; @} \
		*) ;;							\
		esac;							\
		${SHCOMMENT} "[$$file]";				\
		${EGREP} ${_CHECK_WRKREF_DIRS:ts|:Q} "${DESTDIR}$$file" \
		    2>/dev/null | ${SED} -e "s|^|$$file:	|";	\
	done
	${RUN}								\
	exec 1>>${ERROR_DIR}/${.TARGET};				\
	if ${_NONZERO_FILESIZE_P} ${ERROR_DIR}/${.TARGET}; then		\
		${ECHO} "*** The above files still have references to the build directory."; \
		${ECHO} "    This is possibly an error that should be fixed by unwrapping"; \
		${ECHO} "    the files or adding missing tools to the package makefile!"; \
	fi
