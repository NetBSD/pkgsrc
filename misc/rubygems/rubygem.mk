# $NetBSD: rubygem.mk,v 1.2 2008/03/11 22:11:32 jlam Exp $
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
#
# We need rubygems>=1.0.1nb1 to actually build the package, but the
# resulting installed gem can run with older versions of rubygems.
#
BUILD_DEPENDS+=	rubygems>=1.0.1nb1:../../misc/rubygems
DEPENDS+=	rubygems>=0.8.7:../../misc/rubygems

# GEMFILE holds the filename of the Gem to install
.if defined(DISTFILES)
GEMFILE?=	${DISTFILES}
.else
GEMFILE?=	${DISTNAME}${EXTRACT_SUFX}
.endif

EXTRACT_SUFX?=	.gem
EXTRACT_ONLY?=	# empty

# Base directory for Gems
GEM_HOME=	${PREFIX}/lib/ruby/gems/${RUBY_VER_DIR}

# Directory for the Gem to install
GEM_NAME?=	${DISTNAME}
GEM_LIBDIR=	${GEM_HOME}/gems/${GEM_NAME}
GEM_DOCDIR=	${GEM_HOME}/doc/${GEM_NAME}

RUBYGEM_PKGPREFIX=	${RUBY_PKGPREFIX}-gem

# RUBYGEM holds the path to RubyGems' gem command
EVAL_PREFIX+=	RUBYGEM_PREFIX=rubygems
RUBYGEM=	${RUBYGEM_PREFIX}/bin/gem

# PLIST support
PLIST_SUBST+=		GEM_HOME=${GEM_HOME:S|^${PREFIX}/||}
PLIST_SUBST+=		GEM_LIBDIR=${GEM_LIBDIR:S|^${PREFIX}/||}
PLIST_SUBST+=		GEM_DOCDIR=${GEM_DOCDIR:S|^${PREFIX}/||}

# print-PLIST support
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_LIBDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_LIBDIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_LIBDIR}"); print; next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_DOCDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_DOCDIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_DOCDIR}"); print; next; }
PRINT_PLIST_AWK+=	/^@dirrm ${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}(\/(gems|cache|doc|specifications))?$$/ \
			{ next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_HOME}"); print; next; }

# Define a build target so that tools, buildink, etc... frameworks are setup
# in case the Gem contains sources to build
.if !target(do-build)
do-build:
	${RUN}mkdir ${WRKSRC}
.endif

# Installation target
do-gem-install:
	${RUN}${SETENV} ${GEM_ENV} ${RUBYGEM} install --local --no-update-sources --no-ri --install-dir ${PREFIX}/${GEM_HOME} ${_DISTDIR}/${GEMFILE} -- --build-args ${CONFIGURE_ARGS}

do-install: do-gem-install
