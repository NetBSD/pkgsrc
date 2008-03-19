# $NetBSD: rubygem.mk,v 1.28 2008/03/19 23:03:22 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install Ruby gems.
#
# Package-settable variables:
#
# BUILD_TARGET
#	The Rakefile target that creates a local gem if using the
#	``rake'' GEM_BUILD method.
#
#	Default: gem
#
# GEM_BUILD
#	The method used to build the local gem.
#
#	Possible: gemspec, rake
#	Default: rake
#
# GEM_CLEANBUILD
#	A list of shell globs representing files to remove from the
#	gem installed in the buildroot.  The file is removed if the
#	path matches the glob and is not in ${WRKSRC}.  The default
#	is "ext/*"
#
#	Example:
#
#	    GEM_CLEANBUILD=	*.o *.${RUBY_DLEXT} mkmf.log	
#
# GEM_NAME
#	The name of the gem to install.  The default value is ${DISTNAME}.
#
# GEMFILE
#	The complete filename of the gem to install.  The default value
#	is ${DISTNAME}.gem.
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

# Default to using rake to build the local gem from the unpacked files.
GEM_BUILD?=	rake

# Build and run-time dependencies.
#
# We need rubygems>=1.0.1nb1 to actually build the package, but the
# resulting installed gem can run with older versions of rubygems.
#
# If we're using rake to build the local gem, then include it as a
# build tool.
#
BUILD_DEPENDS+=	rubygems>=1.0.1nb1:../../misc/rubygems
DEPENDS+=	rubygems>=1.0.1:../../misc/rubygems
.if ${GEM_BUILD} == "rake"
BUILD_DEPENDS+=	rake>=0.8.1:../../devel/rake
.endif

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

# Installed gems have wrapper scripts that call the right interpreter,
# regardless of the #! line at the head of a script, so we can skip
# the interpreter path check for gems.
#
CHECK_INTERPRETER_SKIP=	${GEM_LIBDIR:S|^${PREFIX}/||}/*

RUBYGEM_PKGPREFIX=	${RUBY_PKGPREFIX}

# RUBYGEM holds the path to RubyGems' gem command
EVAL_PREFIX+=	RUBYGEM_PREFIX=rubygems
RUBYGEM=	${RUBYGEM_PREFIX}/bin/gem

# RAKE holds the path to the rake build tool.
EVAL_PREFIX+=	RAKE_PREFIX=rake
RAKE=		${RAKE_PREFIX}/bin/rake

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
### gem-extract
###
### The gem-extract target extracts a standard gem file.  A standard
### gem file contains:
###
###	data.tar.gz	contains the actual files to build, install, etc.
###	metadata.gz	YAML specification file
###
_GEMSPEC_FILE=	${WRKDIR}/${PKGBASE:S|^${RUBY_PKGPREFIX}-||}.gemspec

.PHONY: gem-extract
do-extract: gem-extract
.if !target(gem-extract)
gem-extract:
	${RUN} cd ${WRKDIR} && ${EXTRACTOR} -f tar ${_DISTDIR:Q}/${GEMFILE:Q}
	${RUN} mkdir ${WRKSRC}
	${RUN} cd ${WRKDIR} && ${EXTRACTOR} metadata.gz && \
		mv metadata ${_GEMSPEC_FILE}
	${RUN} cd ${WRKSRC} && ${EXTRACTOR} -f tar ${WRKDIR:Q}/data.tar.gz
	${RUN} cd ${WRKDIR} && rm -f data.tar.gz* metadata.gz*
.endif

###
### gem-build
###
### The gem-build target builds a new local gem from the extracted gem's
### contents.  The new gem as created as ${WRKSRC}/${GEM_NAME}.gem.
### The local gem is then installed into a special build root under
### ${WRKDIR} (${_RUBYGEM_BUILDROOT}), possibly compiling any extensions.
###
GEM_CLEANBUILD?=	ext/*
.if !empty(GEM_CLEANBUILD:M/*) || !empty(GEM_CLEANBUILD:M*../*)
PKG_FAIL_REASON=	"GEM_CLEANBUILD must be relative to "${GEM_LIBDIR:Q}"."
.endif

_GEM_BUILD_TARGETS=	_gem-${GEM_BUILD}-build
_GEM_BUILD_TARGETS+=	_gem-build-buildroot
.if !empty(GEM_CLEANBUILD)
_GEM_BUILD_TARGETS+=	_gem-build-cleanbuild
.endif

.ORDER: ${_GEM_BUILD_TARGETS}

.PHONY: gem-build
do-build: gem-build
gem-build: ${_GEM_BUILD_TARGETS}

.PHONY: _gem-gemspec-build
_gem-gemspec-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${RUBYGEM} build ${_GEMSPEC_FILE}

BUILD_TARGET?=	gem

.PHONY: _gem-rake-build
_gem-rake-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RAKE} ${BUILD_TARGET}
	${RUN} cd ${WRKSRC} && rm -f ${GEM_NAME}.gem
	${RUN} cd ${WRKSRC} && find . -name ${GEM_NAME}.gem -print | \
	while read file; do \
		ln -fs "$$file" ${GEM_NAME}.gem; \
		exit 0; \
	done

_RUBYGEM_BUILDROOT=	${WRKDIR}/.inst
_RUBYGEM_OPTIONS=	--no-update-sources	# don't cache the gem index
_RUBYGEM_OPTIONS+=	--install-dir ${GEM_HOME}
_RUBYGEM_OPTIONS+=	--build-root ${_RUBYGEM_BUILDROOT}
_RUBYGEM_OPTIONS+=	--local ${WRKSRC}/${GEM_NAME}.gem
_RUBYGEM_OPTIONS+=	-- --build-args ${CONFIGURE_ARGS}

.PHONY: _gem-build-buildroot
_gem-build-buildroot:
	@${STEP_MSG} "Installing gem into buildroot"
	${RUN} ${SETENV} ${MAKE_ENV} ${RUBYGEM} install ${_RUBYGEM_OPTIONS}

.if !empty(GEM_CLEANBUILD)
.PHONY: _gem-build-cleanbuild
_gem-build-cleanbuild:
	@${STEP_MSG} "Cleaning intermediate gem build files"
	${RUN} cd ${_RUBYGEM_BUILDROOT}${GEM_LIBDIR} &&			\
	find . -print | sort -r |					\
	while read file; do						\
		case $$file in						\
		${GEM_CLEANBUILD:@.p.@./${.p.}) ;;@}			\
		*)	continue ;;					\
		esac;							\
		[ ! -e ${WRKSRC:Q}"/$$file" ] || continue;		\
		if [ -d "$$file" ]; then				\
			echo "rmdir "${GEM_LIBDIR:T}"/$$file";		\
			rmdir $$file;					\
		else							\
			echo "rm "${GEM_LIBDIR:T}"/$$file";		\
			rm -f $$file;					\
		fi;							\
	done
.endif

###
### gem-install
###
### The gem-install target installs the gem in ${_RUBY_BUILDROOT} into
### the actual gem repository.
###
GENERATE_PLIST+=	${RUBYGEM_GENERATE_PLIST}
RUBYGEM_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${_RUBYGEM_BUILDROOT}${PREFIX} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} \! -type d -print | \
		${SORT} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} -type d -print | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ," );

.PHONY: gem-install
do-install: gem-install
gem-install:
	${RUN} cd ${_RUBYGEM_BUILDROOT}${PREFIX} && \
		pax -rwpe . ${DESTDIR}${PREFIX}
