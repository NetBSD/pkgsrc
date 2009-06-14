# $NetBSD: rubygem.mk,v 1.43 2009/06/14 18:12:48 minskim Exp $
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
#	gem installed in the installation root.  The file is removed
#	if the path matches the glob and is not in ${WRKSRC}.  The
#	default is "ext/*"
#
#	Example:
#
#	    GEM_CLEANBUILD=	*.o *.${RUBY_DLEXT} mkmf.log	
#
# GEM_NAME
#	The name of the gem to install.  The default value is ${DISTNAME}.
#
# GEM_SPECFILE
#	The path to the gemspec file to use when building a gem using
#       the ``gemspec'' GEM_BUILD method.  It defaults to
#	${WRKDIR}/${DISTNAME}.gemspec.
#
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

PRIVILEGED_STAGES+=	clean

# By default, assume that gems are capable of user-destdir installation.
PKG_DESTDIR_SUPPORT?=	user-destdir

# replace interpeter bin default
REPLACE_RUBY_DIRS?=	bin
REPLACE_RUBY_PAT?=	*

# Include this early in case some of its target are needed
.include "../../lang/ruby/modules.mk"

# Default to using rake to build the local gem from the unpacked files.
GEM_BUILD?=	rake

# Build and run-time dependencies.
#
# We need rubygems>=1.1.0 to actually build the package, but the
# resulting installed gem can run with older versions of rubygems.
#
# If we're using rake to build the local gem, then include it as a
# build tool.
#
BUILD_DEPENDS+=	rubygems>=1.1.0:../../misc/rubygems
DEPENDS+=	rubygems>=1.0.1:../../misc/rubygems
.if ${GEM_BUILD} == "rake"
BUILD_DEPENDS+=	rake>=0.8.1:../../devel/rake
.endif

CATEGORIES+=	ruby
MASTER_SITES?=	http://gems.rubyforge.org/gems/

EXTRACT_SUFX?=	.gem
DISTFILES?=	${DISTNAME}${EXTRACT_SUFX}

# If any of the DISTFILES are gems, then skip the normal do-extract actions
# and extract them ourselves in gem-extract.
#
.if !empty(DISTFILES:M*.gem)
EXTRACT_ONLY?=	# empty
.endif

# Base directory for Gems
GEM_HOME=	${PREFIX}/lib/ruby/gems/${RUBY_VER_DIR}
MAKE_ENV+=	GEM_PATH=${GEM_HOME}

# Directory for the Gem to install
GEM_NAME?=	${DISTNAME}
GEM_LIBDIR=	${GEM_HOME}/gems/${GEM_NAME}
GEM_DOCDIR=	${GEM_HOME}/doc/${GEM_NAME}
GEM_CACHEDIR=	${GEM_HOME}/cache

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
PRINT_PLIST_AWK+=	/^${GEM_LIBDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_LIBDIR:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_LIBDIR}"); print; next; }
PRINT_PLIST_AWK+=	/^${GEM_DOCDIR:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}/ \
			{ gsub(/${GEM_HOME:S|${PREFIX}/||:S|/|\\/|g}/, "$${GEM_HOME}"); print; next; }

###
### gem-extract
###
### The gem-extract target extracts a standard gem file.  It is an
### automatic dependency for the post-extract target so it doesn't
### disturb the usual do-extract actions.
###
GEM_SPECFILE?=	${WRKDIR}/${DISTNAME}.gemspec

.PHONY: gem-extract
post-extract: gem-extract
.if !target(gem-extract)
gem-extract: fake-home
.  for _gem_ in ${DISTFILES:M*.gem}
	${RUN} cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} \
		${RUBYGEM} unpack ${_DISTDIR:Q}/${_gem_:Q}
	${RUN} cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} TZ= \
		${RUBYGEM} spec ${_DISTDIR:Q}/${_gem_:Q} > ${_gem_}spec
.  endfor
.endif

###
### gem-build
###
### The gem-build target builds a new local gem from the extracted gem's
### contents.  The new gem as created as ${WRKSRC}/${GEM_NAME}.gem.
### The local gem is then installed into a special build root under
### ${WRKDIR} (${_RUBYGEM_INSTALL_ROOT}), possibly compiling any extensions.
###
GEM_CLEANBUILD?=	ext/*
.if !empty(GEM_CLEANBUILD:M/*) || !empty(GEM_CLEANBUILD:M*../*)
PKG_FAIL_REASON=	"GEM_CLEANBUILD must be relative to "${GEM_LIBDIR:Q}"."
.endif

.PHONY: gem-build
do-build: gem-build
gem-build: _gem-${GEM_BUILD}-build

.PHONY: _gem-gemspec-build
_gem-gemspec-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} \
		${RUBYGEM} build ${GEM_SPECFILE}
	${RUN} ${TEST} -f ${WRKSRC}/${GEM_NAME}.gem || \
		${FAIL_MSG} "Build of ${GEM_NAME}.gem failed."

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

_RUBYGEM_INSTALL_ROOT=	${WRKDIR}/.inst
_RUBYGEM_OPTIONS=	--no-update-sources	# don't cache the gem index
_RUBYGEM_OPTIONS+=	--install-dir ${GEM_HOME}
_RUBYGEM_OPTIONS+=	--install-root ${_RUBYGEM_INSTALL_ROOT}
_RUBYGEM_OPTIONS+=	--ignore-dependencies
_RUBYGEM_OPTIONS+=	--local ${WRKSRC}/${GEM_NAME}.gem
_RUBYGEM_OPTIONS+=	-- --build-args ${CONFIGURE_ARGS}

.PHONY: _gem-build-install-root
_gem-build-install-root:
	@${STEP_MSG} "Installing gem into installation root"
	${RUN} ${SETENV} ${MAKE_ENV} ${RUBYGEM} install ${_RUBYGEM_OPTIONS}

# The ``gem'' command doesn't exit with a non-zero result even if the
# install of the gem failed, so we do the check and return the proper exit
# code ourselves.
# 
.PHONY: _gem-build-install-root-check
_gem-build-install-root-check:
	${RUN} ${TEST} -f ${_RUBYGEM_INSTALL_ROOT}${GEM_CACHEDIR}/${GEM_NAME}.gem || \
		${FAIL_MSG} "Installing ${GEM_NAME}.gem into installation root failed."

.if !empty(GEM_CLEANBUILD)
.PHONY: _gem-build-cleanbuild
_gem-build-cleanbuild:
	@${STEP_MSG} "Cleaning intermediate gem build files"
	${RUN} cd ${_RUBYGEM_INSTALL_ROOT}${GEM_LIBDIR} &&			\
	find . -print | sort -r |					\
	while read file; do						\
		case $$file in						\
		${GEM_CLEANBUILD:@.p.@./${.p.}) ;;@}			\
		*)	continue ;;					\
		esac;							\
		[ ! -e ${WRKSRC:Q}"/$$file" ] || continue;		\
		if [ -d "$$file" ]; then				\
			${ECHO} "rmdir "${GEM_LIBDIR:T}"/$$file";	\
			rmdir $$file;					\
		else							\
			${ECHO} "rm "${GEM_LIBDIR:T}"/$$file";		\
			rm -f $$file;					\
		fi;							\
	done
.endif

###
### gem-install
###
### The gem-install target installs the gem in ${_RUBY_INSTALL_ROOT} into
### the actual gem repository.
###
GENERATE_PLIST+=	${RUBYGEM_GENERATE_PLIST}
RUBYGEM_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${_RUBYGEM_INSTALL_ROOT}${PREFIX} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} \! -type d -print | \
		${SORT} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} -type d -print | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ," );

_GEM_INSTALL_TARGETS=	_gem-build-install-root
_GEM_INSTALL_TARGETS+=	_gem-build-install-root-check
.if !empty(GEM_CLEANBUILD)
_GEM_INSTALL_TARGETS+=	_gem-build-cleanbuild
.endif
_GEM_INSTALL_TARGETS+=	_gem-install

.ORDER: ${_GEM_INSTALL_TARGETS}

USE_TOOLS+=	pax

do-install: ${_GEM_INSTALL_TARGETS}

.PHONY: _gem-install
_gem-install:
	${RUN} cd ${_RUBYGEM_INSTALL_ROOT}${PREFIX} && \
		pax -rwpe . ${DESTDIR}${PREFIX}
