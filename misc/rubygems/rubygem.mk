# $NetBSD: rubygem.mk,v 1.18 2008/03/14 15:25:28 jlam Exp $
#
# This Makefile fragment is intended to be included by packages that build
# and install Ruby gems.
#
# Package-settable variables:
#
# GEM_BUILD
#	The method used to build the local gem.
#
#	Possible: gemspec, rake
#	Default: rake
#
# GEM_CLEANBUILD
#	A list of shell globs representing files to remove from the
#	gem installed in the buildroot.  The default is an empty list.
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
DEPENDS+=	rubygems>=0.9.4:../../misc/rubygems
.if ${GEM_BUILD} == "rake"
BUILD_DEPENDS+=	rake-[0-9]*:../../devel/rake
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
gem-extract:
	${RUN} cd ${WRKDIR} && ${EXTRACTOR} -f tar ${_DISTDIR:Q}/${GEMFILE:Q}
	${RUN} mkdir ${WRKSRC}
	${RUN} cd ${WRKSRC} && ${EXTRACTOR} -f tar ${WRKDIR:Q}/data.tar.gz
	${RUN} cd ${WRKDIR} && ${EXTRACTOR} metadata.gz && \
		mv metadata ${_GEMSPEC_FILE}
	${RUN} cd ${WRKDIR} && rm -f data.tar.gz* metadata.gz*

###
### gem-build
###
### The gem-build target builds a new local gem from the extracted gem's
### contents.  The new gem as created as ${WRKSRC}/${GEM_NAME}.gem.
###
.PHONY: gem-build gem-gemspec-build gem-rake-build
do-build: gem-build

gem-build: gem-${GEM_BUILD}-build

gem-gemspec-build:
	${RUN} cd ${WRKSRC} && ${RUBYGEM} build ${_GEMSPEC_FILE}

gem-rake-build:
	${RUN} cd ${WRKSRC} && ${RAKE} gem
	${RUN} cd ${WRKSRC} && rm -f ${GEM_NAME}.gem
	${RUN} cd ${WRKSRC} && find . -name ${GEM_NAME}.gem -print | \
	while read file; do \
		ln -fs "$$file" ${GEM_NAME}.gem; \
		exit 0; \
	done

###
### gem-install
###
### The gem-install target installs the local gem in ${WRKDIR} into
### the gem repository.  We this this as a staged installation
### (independent of PKG_DESTDIR_SUPPORT) because it can potentially
### build software and we want that to happen within ${WRKDIR}.
###
_RUBYGEM_BUILDROOT=	${WRKDIR}/.inst
_RUBYGEM_OPTIONS=	--no-update-sources	# don't cache the gem index
_RUBYGEM_OPTIONS+=	--install-dir ${GEM_HOME}
_RUBYGEM_OPTIONS+=	--build-root ${_RUBYGEM_BUILDROOT}
_RUBYGEM_OPTIONS+=	--local ${WRKSRC}/${GEM_NAME}.gem
_RUBYGEM_OPTIONS+=	-- --build-args ${CONFIGURE_ARGS}

GENERATE_PLIST+=	${RUBYGEM_GENERATE_PLIST}
RUBYGEM_GENERATE_PLIST=	\
	${ECHO} "@comment The following lines are automatically generated." && \
	( cd ${_RUBYGEM_BUILDROOT}${PREFIX} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} \! -type d -print | \
		${SORT} && \
	  ${FIND} ${GEM_DOCDIR:S|${PREFIX}/||} -type d -print | \
		${SORT} -r | ${SED} -e "s,^,@dirrm ," );
	

_GEM_INSTALL_TARGETS=	_gem-install-buildroot
_GEM_INSTALL_TARGETS+=	_gem-install-cleanbuild
_GEM_INSTALL_TARGETS+=	_gem-install-copy

.PHONY: gem-install ${_GEM_INSTALL_TARGETS}
.ORDER: ${_GEM_INSTALL_TARGETS}

do-install: gem-install
gem-install: ${_GEM_INSTALL_TARGETS}

_gem-install-buildroot:
	@${STEP_MSG} "Installing gem into buildroot"
	${RUN} ${SETENV} ${INSTALL_ENV} ${MAKE_ENV} \
		${RUBYGEM} install ${_RUBYGEM_OPTIONS}

GEM_CLEANBUILD?=	# empty
.if !empty(GEM_CLEANBUILD:M/*) || !empty(GEM_CLEANBUILD:M*../*)
PKG_FAIL_REASON=	"GEM_CLEANBUILD must be relative to "${GEM_LIBDIR:Q}"."
.endif

_gem-install-cleanbuild:
	@${STEP_MSG} "Cleaning intermediate gem build files"
.if !empty(GEM_CLEANBUILD)
	${RUN} cd ${_RUBYGEM_BUILDROOT}${GEM_LIBDIR} &&			\
	ls ${GEM_CLEANBUILD} |						\
	while read file; do						\
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
	${RUN} if [ -d ${_RUBYGEM_BUILDROOT}${GEM_LIBDIR}/ext ]; then	\
		cd ${_RUBYGEM_BUILDROOT}${GEM_LIBDIR} &&		\
		find ext -print | sort -r |				\
		while read file; do					\
			[ ! -e ${WRKSRC:Q}"/$$file" ] || continue;	\
			if [ -d "$$file" ]; then			\
				echo "rmdir "${GEM_LIBDIR:T}"/$$file";	\
				rmdir $$file;				\
			else						\
				echo "rm "${GEM_LIBDIR:T}"/$$file";	\
				rm -f $$file;				\
			fi;						\
		done;							\
	fi

_gem-install-copy:
	@${STEP_MSG} "Copying gem into installation directory"
	${RUN} cd ${_RUBYGEM_BUILDROOT}${PREFIX} && \
		pax -rwpe . ${DESTDIR}${PREFIX}
