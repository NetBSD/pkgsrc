# $NetBSD: rubygem.mk,v 1.8 2008/03/12 22:04:07 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install Ruby gems.
#
# Package-settable variables:
#
# GEM_NAME
#	The name of the gem to install.  The default value is ${DISTNAME}.
#
# GEMFILE
#	The complete filename of the gem to install.  It defaults to
#	${DISTNAME}.gem.
#
# Variables defined in this file:
#
# GEM_DOCDIR
#	The path to the directory in the local gem repository that holds
#	the documentation for the installed gem.
#
# GEM_HOME
#	The path to the local gem repository.
#
# GEM_LIBDIR
#	The path to the directory in the local gem repository that holds
#	the contents of the installed gem.
#
# RAKE
#	The path to the ``rake'' binary.
#
# RUBYGEM_PKGPREFIX
#	The recommended prefix for the PKGNAME.
#
# RUBYGEM
#	The path to the rubygems ``gem'' script.
#

# By default, assume that gems are capable of user-destdir installation.
PKG_DESTDIR_SUPPORT?=	user-destdir

# Include this early in case some of its target are needed
.include "../../lang/ruby/modules.mk"

# Build and run-time dependencies.
#
# We need rubygems>=1.0.1nb1 to actually build the package, but the
# resulting installed gem can run with older versions of rubygems.
#
BUILD_DEPENDS+=	rake-[0-9]*:../../devel/rake
BUILD_DEPENDS+=	rubygems>=1.0.1nb1:../../misc/rubygems
DEPENDS+=	rubygems>=0.8.7:../../misc/rubygems

# GEMFILE holds the filename of the Gem to install
.if defined(DISTFILES)
GEMFILE?=	${DISTFILES}
.else
GEMFILE?=	${DISTNAME}${EXTRACT_SUFX}
.endif

CATEGORIES+=	ruby
MASTER_SITES?=	http://gems.rubyforge.org/gems/

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
EVAL_PREFIX+=	RAKE_PREFIX=rake
RAKE=		${RAKE_PREFIX}/bin/rake
RUBYGEM=	${RUBYGEM_PREFIX}/bin/gem

# PLIST support
PLIST_SUBST+=		GEM_HOME=${GEM_HOME:S|^${PREFIX}/||}
PLIST_SUBST+=		GEM_LIBDIR=${GEM_LIBDIR:S|^${PREFIX}/||}
PLIST_SUBST+=		GEM_DOCDIR=${GEM_DOCDIR:S|^${PREFIX}/||}

# print-PLIST support
PRINT_PLIST_AWK+=	/${GEM_NAME:S/./[.]/g}[.](gem|gemspec)$$/ \
			{ gsub(/${PKGVERSION_NOREV:S|/|\\/|g}[.]gem/, "$${PKGVERSION}.gem"); }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_LIBDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_LIBDIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_LIBDIR}"); print; next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_DOCDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ next; }
PRINT_PLIST_AWK+=	/^@dirrm ${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}(\/(gems|cache|doc|specifications))?$$/ \
			{ next; }
PRINT_PLIST_AWK+=	/^@dirrm lib\/ruby\/gems$$/ { next; }
PRINT_PLIST_AWK+=	/^(@dirrm )?${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_HOME}"); print; next; }

###
### do-gem-extract
###
### The do-gem-extract target extracts a standard gem file.  A standard
### gem file contains:
###
###	data.tar.gz	contains the actual files to build, install, etc.
###	metadata.gz	YAML specification file
###
.PHONY: do-gem-extract
do-extract: do-gem-extract
do-gem-extract:
	${RUN} cd ${WRKDIR} && \
		${EXTRACTOR} -f tar ${_DISTDIR:Q}/${GEMFILE:Q} data.tar.gz
	${RUN} mkdir ${WRKSRC}
	${RUN} cd ${WRKSRC} && \
		${EXTRACTOR} -f tar ${WRKDIR:Q}/data.tar.gz
	${RUN} rm -f ${WRKDIR:Q}/data.tar.gz

###
### do-gem-build
###
### The do-gem-build target builds a new local gem from the extracted
### gem's contents.  The new gem as created as ${WRKSRC}/pkg/${GEMFILE}.
###
.PHONY: do-gem-build
do-build: do-gem-build
do-gem-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE} gem

###
### do-gem-install
###
### The do-gem-install target installs the local gem in ${WRKDIR} into
### the gem repository.  We this this as a staged installation
### (independent of PKG_DESTDIR_SUPPORT) because it can potentially
### build software and we want that to happen within ${WRKDIR}.
###
_RUBYGEM_BUILDROOT=	${WRKDIR}/.inst
_RUBYGEM_OPTIONS=	--no-update-sources	# don't cache the gem index
_RUBYGEM_OPTIONS+=	--install-dir ${GEM_HOME}
_RUBYGEM_OPTIONS+=	--build-root ${_RUBYGEM_BUILDROOT}
_RUBYGEM_OPTIONS+=	--local ${WRKSRC}/pkg/${GEMFILE}
_RUBYGEM_OPTIONS+=	-- --build-args ${CONFIGURE_ARGS}

GENERATE_PLIST+=	${RUBYGEM_GENERATE_PLIST}
RUBYGEM_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${_RUBYGEM_BUILDROOT}${PREFIX} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} \! -type d -print | \
		${SORT} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} -type d -print | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ," );
	

.PHONY: do-gem-install
do-install: do-gem-install
do-gem-install:
	@${STEP_MSG} "Installing gem into buildroot"
	${RUN} ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${RUBYGEM} install ${_RUBYGEM_OPTIONS}
	${RUN} if [ -d ${_RUBYGEM_BUILDROOT}${GEM_LIBDIR}/ext ]; then \
		cd ${_RUBYGEM_BUILDROOT}${GEM_LIBDIR}/ext && ls | \
		while read file; do \
			if [ ! -f ${WRKSRC}/ext/$$file ]; then \
				echo "rm "${GEM_LIBDIR:T}"/ext/$$file"; \
				rm -f $$file; \
			fi; \
		done; \
	fi
	@${STEP_MSG} "Copying files into installation directory"
	${RUN} cd ${_RUBYGEM_BUILDROOT}${PREFIX} && \
		pax -rwpe . ${DESTDIR}${PREFIX}
