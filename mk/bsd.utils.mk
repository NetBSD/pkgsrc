# $NetBSD: bsd.utils.mk,v 1.2 2006/01/18 03:58:19 jlam Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines utility
# and otherwise miscellaneous variables and targets.
#

# DEPENDS_TYPE is used by the "show-depends-pkgpaths" target and specifies
# which class of dependencies to output.  The special value "all" means
# to output every dependency.
#
DEPENDS_TYPE?=  all
.if !empty(DEPENDS_TYPE:Mbuild) || !empty(DEPENDS_TYPE:Mall)
_ALL_DEPENDS_PKGPATHS+=	\
	${BUILD_DEPENDS:C/^[^:]*://:S/^..\/..\///:S/${PKGSRCDIR}\///}
.endif
.if !empty(DEPENDS_TYPE:Minstall) || !empty(DEPENDS_TYPE:Mpackage) || \
    !empty(DEPENDS_TYPE:Mall)
_ALL_DEPENDS_PKGPATHS+=	\
	${DEPENDS:C/^[^:]*://:S/^..\/..\///:S/${PKGSRCDIR}\///}
.endif

.PHONY: show-depends-pkgpaths
show-depends-pkgpaths:
.for _deppath_ in ${_ALL_DEPENDS_PKGPATHS:O:u}
	@${ECHO} ${_deppath_}
.endfor

# _DEPENDS_WALK_CMD holds the command (sans arguments) to walk the
# dependency graph for a package.
#
_DEPENDS_WALK_MAKEFLAGS?=	${MAKEFLAGS}
_DEPENDS_WALK_CMD=							\
	${SETENV} ECHO=${TOOLS_ECHO:Q} MAKE=${MAKE:Q}			\
		MAKEFLAGS=${_DEPENDS_WALK_MAKEFLAGS:Q}			\
		PKGSRCDIR=${PKGSRCDIR:Q} TEST=${TOOLS_TEST:Q}		\
	${AWK} -f ${.CURDIR}/../../mk/scripts/depends-depth-first.awk --
