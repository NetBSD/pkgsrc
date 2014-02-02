# $NetBSD: gem.mk,v 1.25 2014/02/02 07:48:35 taca Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install Ruby gems.
#
# Package-settable variables:
#
# RUBYGEMS_REQD
#	Minimum version of required rubygems.  Ruby base packages contain:
#
#		ruby18-base:	none
#		ruby193-base:	1.8.23
#		ruby200-base:	2.0.3
#
#	If newer version of rubygems is resuiqred, set RUBYGEMS_REQD to
#	minimum version.
#
#	Default: not defined
#
# OVERRIDE_GEMSPEC
#	Fix version of depending gem or modify files in gemspec.
#
#	(1) Specify as gem and dependency pattern as usual pkgsrc's one.
#
#		Example:
#		    When gemspec contains "json~>1.4.7" as runtime dependency
#		    (i.e. json>=1.4.7<1.5) and if you want to relax it to
#		    "json>=1.4.6" then use:
#
#			OVERRIDE_GEMSPEC+= json>=1.4.6
#
#		    If you want to change depending gem to "json_pure>=1.4.6"
#		    then use:
#
#			OVERRIDE_GEMSPEC+= json:json_pure>=1.4.6
#
#		    You can also remove dependency:
#
#			OVERRIDE_GEMSPEC+= json:
#
#	(2) Modify instance of gemspec.
#
#		Example:
#			Rename gem's name to "foo" (setting instance @name):
#
#			OVERRIDE_GEMSPEC+= :name=foo
#
#		Example:
#			Remove files (a.rb and b.rb) from 'files':
#
#			OVERRIDE_GEMSPEC+= :files a.rb= b.rb=
#
#		Example:
#			Add a file (exec.rb) to 'executables':
#
#			OVERRIDE_GEMSPEC+= :executables exec.rb
#
#		Example:
#			Rename a file (from 'ruby' to 'ruby193') in 'files':
#
#			OVERRIDE_GEMSPEC+= :files ruby=ruby193
#
#	Note: Because of limited parser, argumetns for (1) must preceed to (2).
#
#	Default: (empty)
#
# GEM_PATH
#	Set GEM_PATH; search path for rubygems
#
#	Default: ${PREFIX}/${GEM_HOME}
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
#	Default: gemspec
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
# RUBYGEM_OPTIONS
#	Optional parameter to pass to gem on install stage.
#
#
# Variables defined in this file:
#
# GEM_DOCDIR
#	The relative path from PREFIX to the directory in the local gem
#	repository that holds the documentation for the installed gem.
#
# GEM_LIBDIR
#	The relative path from PREFIX to the directory in the local gem
#	repository that holds the contents of the installed gem.
#
# RUBYGEM
#	The path to the rubygems ``gem'' script.
#
.if !defined(_RUBYGEM_MK)
_RUBYGEM_MK=	# defined

# replace interpeter bin default
REPLACE_RUBY_DIRS?=	bin
REPLACE_RUBY_PAT?=	*

# Default to using rake to build the local gem from the unpacked files.
GEM_BUILD?=	gemspec

OVERRIDE_GEMSPEC?=	# default is empty

RUBYGEM_LANG?=	en_US.UTF-8
RUBYGEM_ENV?=	LANG=${RUBYGEM_LANG} LC_CTYPE=${RUBYGEM_LANG}

.if !empty(OVERRIDE_GEMSPEC)
UPDATE_GEMSPEC=		../../lang/ruby/files/update-gemspec.rb
.endif

.if ${GEM_BUILD} == "rake"
USE_RAKE?=		YES
.endif

# print-PLIST support
PRINT_PLIST_AWK+=	/${GEM_NAME}\.info$$/ \
			{ gsub(/${GEM_NAME}\.info/, "$${GEM_NAME}.info"); }
PRINT_PLIST_AWK+=	/${GEM_NAME}\.(gem|gemspec)$$/ \
			{ gsub(/${GEM_NAME}\.gem/, "$${GEM_NAME}.gem"); }
PRINT_PLIST_AWK+=	/${GEM_NAME:S/./[.]/g}[.](gem|gemspec)$$/ \
	{ gsub(/${PKGVERSION_NOREV:S|/|\\/|g}[.]gem/, "$${PKGVERSION}.gem"); }
PRINT_PLIST_AWK+=	/^${GEM_LIBDIR:S|/|\\/|g}/ \
	{ gsub(/${GEM_LIBDIR:S|/|\\/|g}/, "$${GEM_LIBDIR}"); print; next; }
PRINT_PLIST_AWK+=	/^${GEM_DOCDIR:S|/|\\/|g}/ \
			{ next; }
PRINT_PLIST_AWK+=	/^${GEM_HOME:S|/|\\/|g}/ \
			{ gsub(/${GEM_HOME:S|/|\\/|g}/, "$${GEM_HOME}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_GEM_BASE:S|/|\\/|g}/ \
		{ gsub(/${RUBY_GEM_BASE:S|/|\\/|g}/, "$${RUBY_GEM_BASE}"); \
			print; next; }

# Include this early in case some of its target are needed
.include "../../lang/ruby/modules.mk"

# Build and run-time dependencies for Ruby prior to 1.9.
#
# We need rubygems>=1.1.0 to actually build the package, but the
# resulting installed gem can run with older versions of rubygems.
#
# If we're using rake to build the local gem, then include it as a
# build tool.
#

.if ${RUBY_VER} == "18"
BUILD_DEPENDS+=	${RUBY_PKGPREFIX}-rubygems>=1.1.0:../../misc/rubygems
DEPENDS+=	${RUBY_PKGPREFIX}-rubygems>=1.0.1:../../misc/rubygems
.else # !ruby18
. if defined(RUBYGEMS_REQD)

RUBY193_RUBYGEMS_VERS=	1.8.11
RUBY200_RUBYGEMS_VERS=	2.0.0

_RUBYGEMS_REQD_MAJOR=	${RUBYGEMS_REQD:C/\.[0-9\.]+$//}
_RUBYGEMS_REQD_MINORS=	${RUBYGEMS_REQD:C/^([0-9]+)\.*//}

.  if ${RUBY_VER} == "193"
_RUBYGEMS_MAJOR=	${RUBY193_RUBYGEMS_VERS:C/\.[0-9\.]+$//}
_RUBYGEMS_MINORS=	${RUBY193_RUBYGEMS_VERS:C/^([0-9]+)\.*//}
.  elif ${RUBY_VER} == "200"
_RUBYGEMS_MAJOR=	${RUBY200_RUBYGEMS_VERS:C/\.[0-9\.]+$//}
_RUBYGEMS_MINORS=	${RUBY200_RUBYGEMS_VERS:C/^([0-9]+)\.*//}
.  else
PKG_FAIL_REASON+= "Unknown Ruby version specified: ${RUBY_VER}."
.  endif

_RUBYGEMS_REQD=	NO

.  if ${_RUBYGEMS_REQD_MAJOR} > ${_RUBYGEMS_MAJOR}
_RUBYGEMS_REQD=	YES
.  elif ${_RUBYGEMS_REQD_MAJOR} == ${_RUBYGEMS_MAJOR}
.   if !empty(_RUBYGEMS_MINORS) && ${_RUBYGEMS_REQD_MINORS} > ${_RUBYGEMS_MINORS}
_RUBYGEMS_REQD=	YES
.   endif
.  endif

.  if empty(_RUBYGEMS_REQD:M[nN][oO])
DEPENDS+=	${RUBY_PKGPREFIX}-rubygems>=${RUBYGEMS_REQD}:../../misc/rubygems
.  endif
. endif
.endif # !ruby18

CATEGORIES+=	ruby
MASTER_SITES?=	${MASTER_SITE_RUBYGEMS}

EXTRACT_SUFX?=	.gem
DISTFILES?=	${DISTNAME}${EXTRACT_SUFX}

# If any of the DISTFILES are gems, then skip the normal do-extract actions
# and extract them ourselves in gem-extract.
#
.if !empty(DISTFILES:M*.gem)
EXTRACT_ONLY?=	# empty
.endif

# Specify GEM_PATH
GEM_PATH?=	${PREFIX}/${GEM_HOME}

# Base directory for Gems
MAKE_ENV+=	GEM_PATH=${GEM_PATH}

# Directory for the Gem to install
GEM_NAME?=	${DISTNAME}
GEM_CACHEDIR=	${GEM_HOME}/cache
GEM_DOCDIR=	${GEM_HOME}/doc/${GEM_NAME}
GEM_LIBDIR=	${GEM_HOME}/gems/${GEM_NAME}

# Installed gems have wrapper scripts that call the right interpreter,
# regardless of the #! line at the head of a script, so we can skip
# the interpreter path check for gems.  ANd it is also true for files'
# permission.
#
CHECK_INTERPRETER_SKIP+=	${GEM_LIBDIR}/*
CHECK_PERMS_SKIP+=		${GEM_LIBDIR}/*

# RUBYGEM holds the path to RubyGems' gem command
EVAL_PREFIX+=	RUBYGEM_PREFIX=${RUBYGEM_NAME}
RUBYGEM=	${RUBYGEM_PREFIX}/bin/${RUBYGEM_NAME}

# PLIST support
PLIST_SUBST+=		GEM_NAME=${GEM_NAME}
PLIST_SUBST+=		GEM_LIBDIR=${GEM_LIBDIR}
PLIST_SUBST+=		GEM_DOCDIR=${GEM_DOCDIR}

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
	${RUN} cd ${WRKDIR} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM} unpack ${_DISTDIR:Q}/${_gem_:Q}
	${RUN} cd ${WRKDIR} && \
		${SETENV} ${MAKE_ENV} TZ=UTC ${RUBYGEM_ENV} \
		${RUBYGEM} spec --ruby ${_DISTDIR:Q}/${_gem_:Q} > ${_gem_}spec
.  endfor
.endif

###
### gem-build
###
### The gem-build target builds a new local gem from the extracted gem's
### contents.  The new gem as created as ${WRKSRC}/${GEM_NAME}.gem.
### The local gem is then installed into a special build root under
### ${WRKDIR} (${RUBYGEM_INSTALL_ROOT}), possibly compiling any extensions.
###
GEM_CLEANBUILD?=	ext/*

.if !empty(GEM_CLEANBUILD:M/*) || !empty(GEM_CLEANBUILD:M*../*)
PKG_FAIL_REASON=	"GEM_CLEANBUILD must be relative to "${PREFIX}/${GEM_LIBDIR:Q}"."
.endif

.PHONY: gem-build
do-build: _gem-pre-build gem-build

_gem-pre-build:
.if !empty(OVERRIDE_GEMSPEC)
	@${STEP_MSG} Override gemspec dependency
	@${RUBY} ${.CURDIR}/${UPDATE_GEMSPEC} ${WRKDIR}/${GEM_NAME}.gemspec \
		${OVERRIDE_GEMSPEC:Q}
.endif
	@${STEP_MSG} "Removing backup files of patch before build"
	@find ${WRKSRC} -name \*.orig -exec rm {} \;

gem-build: _gem-${GEM_BUILD}-build

.PHONY: _gem-gemspec-build
_gem-gemspec-build:
	${RUN} cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
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

RUBYGEM_INSTALL_ROOT=	${WRKDIR}/.inst
_RUBYGEM_OPTIONS=	--no-update-sources	# don't cache the gem index
_RUBYGEM_OPTIONS+=	--install-dir ${PREFIX}/${GEM_HOME}
_RUBYGEM_OPTIONS+=	${RUBYGEM_INSTALL_ROOT_OPTION}
_RUBYGEM_OPTIONS+=	--ignore-dependencies
_RUBYGEM_OPTIONS+=	--local ${WRKSRC}/${GEM_NAME}.gem
.if !empty(RUBY_BUILD_RI:M[nN][oO])
_RUBYGEM_OPTIONS+=	--no-ri
.endif
.if !empty(RUBY_BUILD_RDOC:M[nN][oO])
_RUBYGEM_OPTIONS+=	--no-rdoc
.endif
.if !empty(CONFIGURE_ARGS)
_RUBYGEM_OPTIONS+=	-- --build-args ${CONFIGURE_ARGS}
.endif

RUBYGEM_INSTALL_ROOT_OPTION=	--install-root ${RUBYGEM_INSTALL_ROOT}

.PHONY: _gem-build-install-root
_gem-build-install-root:
	@${STEP_MSG} "Installing gem into installation root"
	${RUN} ${SETENV} ${MAKE_ENV} ${RUBYGEM_ENV} \
		${RUBYGEM} install --backtrace ${RUBYGEM_OPTIONS} ${_RUBYGEM_OPTIONS}

# The ``gem'' command doesn't exit with a non-zero result even if the
# install of the gem failed, so we do the check and return the proper exit
# code ourselves.
#
.PHONY: _gem-build-install-root-check
_gem-build-install-root-check:
	${RUN} ${TEST} -f ${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_CACHEDIR}/${GEM_NAME}.gem || \
		${FAIL_MSG} "Installing ${GEM_NAME}.gem into installation root failed."

.if !empty(GEM_CLEANBUILD)
.PHONY: _gem-build-cleanbuild
_gem-build-cleanbuild:
	@${STEP_MSG} "Cleaning intermediate gem build files"
	${RUN} cd ${RUBYGEM_INSTALL_ROOT}${PREFIX}/${GEM_LIBDIR} &&	\
	find . -print | sort -r |					\
	while read file; do						\
		case $$file in						\
		${GEM_CLEANBUILD:@.p.@./${.p.}) ;;@}			\
		*)	continue ;;					\
		esac;							\
		if [ -e ${WRKSRC:Q}"/$$file" ]; then			\
			continue;					\
		elif [ -d "$$file" ]; then				\
			rfile=`echo $$file | ${SED} -e 's|^\./||'`;	\
			${ECHO} "rmdir "${GEM_NAME}"/$$rfile";		\
			rmdir $$file;					\
		elif [ -f "$$file" ]; then				\
			rfile=`echo $$file | ${SED} -e 's|^\./||'`;	\
			${ECHO} "rm "${GEM_NAME}"/$$rfile";		\
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
	( cd ${RUBYGEM_INSTALL_ROOT}${PREFIX} && test -d ${GEM_DOCDIR} && \
	  ${FIND} ${GEM_DOCDIR} \! -type d -print | ${SORT} ) || true;

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
	@${STEP_MSG} "gem install"
	${RUN} cd ${RUBYGEM_INSTALL_ROOT}${PREFIX} && \
		pax -rwpe . ${DESTDIR}${PREFIX}

.endif
