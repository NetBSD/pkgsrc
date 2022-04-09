# $NetBSD: bsd.utils.mk,v 1.13 2022/04/09 00:46:12 rillig Exp $
#
# This Makefile fragment is included by bsd.pkg.mk and defines utility
# and otherwise miscellaneous variables and targets.
#

# DEPENDS_TYPE
#	Used by the "show-depends-pkgpaths" target to specify which
#	class of direct dependencies to output.  The special value "all"
#	means to output every dependency.
#
#	Possible:
#		all		= build
#				+ TEST_DEPENDS (if PKGSRC_RUN_TEST)
#				+ install
#		build		= BOOTSTRAP_DEPENDS
#				+ TOOL_DEPENDS
#				+ BUILD_DEPENDS
#		install		= DEPENDS
#		package		XXX: same as install?
#
#	Default:
#		all
#
# Keywords: depends dependencies
DEPENDS_TYPE?=  all
.if !empty(DEPENDS_TYPE:Mbuild) || !empty(DEPENDS_TYPE:Mall)
_ALL_DEPENDS+=	${BOOTSTRAP_DEPENDS} ${BUILD_DEPENDS} ${TOOL_DEPENDS}
.  if !empty(PKGSRC_RUN_TEST:M[yY][eE][sS])
_ALL_DEPENDS+=	${TEST_DEPENDS}
.  endif
.endif
.if !empty(DEPENDS_TYPE:Minstall) || !empty(DEPENDS_TYPE:Mpackage) || \
    !empty(DEPENDS_TYPE:Mall)
_ALL_DEPENDS+=	${DEPENDS}
.endif

# _PKG_PATHS_CMD canonicalizes package paths so that they're relative to
# ${PKGSRCDIR} and also verifies that they exist within pkgsrc.
#
_PKG_PATHS_CMD=								\
	${PKGSRC_SETENV} ECHO=${TOOLS_ECHO:Q} PKGSRCDIR=${PKGSRCDIR:Q}	\
		PWD_CMD=${TOOLS_PWD_CMD:Q} TEST=${TOOLS_TEST:Q}		\
	${SH} ${.CURDIR}/../../mk/scripts/pkg_path

# show-depends-dirs:
# show-depends-pkgpaths:
#	Lists the PKGPATH of all direct dependencies of the current
#	package.
#
#	Parameters:
#		PKGSRC_RUN_TEST
#			Whether to include test dependencies as well.
#
#	See also:
#		show-depends
#		show-depends-all
#
# Keywords: depends dependencies
.PHONY: show-depends-dirs show-depends-pkgpaths
show-depends-dirs show-depends-pkgpaths:
	@${_PKG_PATHS_CMD} ${_ALL_DEPENDS:C/^[^:]*://:O:u}

# _DEPENDS_WALK_CMD holds the command (sans arguments) to walk the
# dependency graph for a package.
#
# XXX Need to handle TOOL_DEPENDS/BUILD_DEPENDS split and cross-compilation.
#
_DEPENDS_WALK_MAKEFLAGS?=	${MAKEFLAGS}
_DEPENDS_WALK_CMD=							\
	${PKGSRC_SETENV} ECHO=${TOOLS_ECHO:Q} MAKE=${MAKE:Q}		\
		MAKEFLAGS=${_DEPENDS_WALK_MAKEFLAGS:Q}			\
		PKGSRCDIR=${PKGSRCDIR:Q} TEST=${TOOLS_TEST:Q}		\
	${AWK} -f ${.CURDIR}/../../mk/scripts/depends-depth-first.awk --

# show-depends-all:
#	Lists the PKGPATH of all direct or indirect dependencies of the
#	current package.
#
#	Parameters:
#		DEPENDS_TYPE
#			all, build, install or package
#		PKGSRC_RUN_TEST
#			Whether to include test dependencies as well.
#
#	See also:
#		show-depends
#		show-depends-pkgpaths
# Keywords: depends dependencies recursive indirect
show-depends-all: .PHONY
	${RUN} ${_DEPENDS_WALK_CMD} ${PKGPATH}
