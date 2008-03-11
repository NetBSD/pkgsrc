# $NetBSD: rubygem.mk,v 1.1 2008/03/11 20:12:17 seb Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install Ruby gems.
#
# The following target is provided by this file:
#
# do-gem-install	installed as a dependency of the do-install target
# 			it install the Ruby Gem ${GEMFILE}.
#
# do-build		Mostly phony target, but necessary for various
# 			pkgsrc framework to work, in case the Gem to install
# 			contains sources to compile.
#
# The following variables may be set prior to including this file:
#
# GEM_NAME		The name of the Gem to install, it defaults
# 			to ${DISTNAME}.
#
# GEMFILE		The filename, in ${_DISTDIR}, of the Gem to install.
#
# If the Gem to install does not contain sources to compile NO_BUILD
# should be defined.
#
# The name, PKGNAME, of the package installing the Gem should probably
# use '${RUBYGEM_PKGPREFIX}-' as a prefix.
#

# Include this early in case some of its target are needed
.include "../../lang/ruby/modules.mk"

# Build and run-time dependency on rubygem
BUILD_DEPENDS+=	rubygems-[0-9]*:../../misc/rubygems
DEPENDS+=	rubygems-[0-9]*:../../misc/rubygems

EXTRACT_SUFX?=	.gem
EXTRACT_ONLY?=	# empty

# Base directory for Gems
GEMS_BASEDIR=	lib/ruby/gems/${RUBY_VER_DIR}

# Directory for the Gem to install
GEM_NAME?=	${DISTNAME}
GEM_LIB_DIR=	${GEMS_BASEDIR}/gems/${GEM_NAME}
GEM_DOC_DIR=	${GEMS_BASEDIR}/doc/${GEM_NAME}

RUBYGEM_PKGPREFIX=	rubygem

# RUBYGEM holds the path to RubyGems' gem command
FIND_PREFIX:=	RUBYGEM_PREFIX=rubygems
.include "../../mk/find-prefix.mk"
RUBYGEM=	${RUBYGEM_PREFIX}/bin/gem

# PLIST support
PLIST_SUBST+=		GEM_LIB_DIR=${GEM_LIB_DIR}
PLIST_SUBST+=		GEM_DOC_DIR=${GEM_DOC_DIR}
PLIST_SUBST+=		GEMS_BASEDIR=${GEMS_BASEDIR}

# print-PLIST support
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_LIB_DIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_LIB_DIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_LIB_DIR}"); print; next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_DOC_DIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_DOC_DIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_DOC_DIR}"); print; next; }
PRINT_PLIST_AWK+=	/^@dirrm ${GEMS_BASEDIR:S|${PREFIX}/||:S|/|\\/|g}(\/(gems|cache|doc|specifications))?$$/ \
			{ next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEMS_BASEDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEMS_BASEDIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEMS_BASEDIR}"); print; next; }

# GEMFILE holds the filename of the Gem to install
.if defined(DISTFILES)
GEMFILE?=	${DISTFILES}
.else
GEMFILE?=	${DISTNAME}${EXTRACT_SUFX}
.endif

# Define a build target so that tools, buildink, etc... frameworks are setup
# in case the Gem contains sources to build
.if !target(do-build)
do-build:
	${RUN}mkdir ${WRKSRC}
.endif

# Installation target
do-gem-install:
	${RUN}${SETENV} ${GEM_ENV} ${RUBYGEM} install --local --no-update-sources --no-ri --install-dir ${PREFIX}/${GEMS_BASEDIR} ${_DISTDIR}/${GEMFILE} -- --build-args ${CONFIGURE_ARGS}

do-install: do-gem-install
