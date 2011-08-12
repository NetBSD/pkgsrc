# $NetBSD: rubyversion.mk,v 1.61 2011/08/12 15:27:44 taca Exp $
#

.if !defined(_RUBYVERSION_MK)
_RUBYVERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# current supported Ruby's version
RUBY18_VERSION=		1.8.7
RUBY19_VERSION=		1.9.2

# patch
RUBY18_PATCHLEVEL=	pl352
RUBY19_PATCHLEVEL=	pl290

# current API compatible version; used for version of shared library
RUBY18_API_VERSION=	1.8.7
RUBY19_API_VERSION=	1.9.1

# RUBY_VERSION_DEFAULT defines default version for Ruby related
#	packages and user can define in mk.conf.  (1.8 or 1.9)
#
RUBY_VERSION_DEFAULT?=	1.8
_RUBY_VERSION_DEFAULT=	${RUBY_VERSION_DEFAULT:S/.//}

# RUBY_VERSION defines the specific Ruby's version which is supported
#	by the package.  It should be defined by packages whose distfiles
#	are contained by Ruby's release distribution.
#
#	Default value is set to ${RUBY_VERSION_DEFAULT}
#
.if defined(RUBY_VERSION_REQD)
.  if ${RUBY_VERSION_REQD} == "18"
RUBY_VERSION?=		${RUBY18_VERSION}
.  elif ${RUBY_VERSION_REQD} == "19"
RUBY_VERSION?=		${RUBY19_VERSION}
.  else
RUBY_VERSION?=		${RUBY18_VERSION}
PKG_FAIL_REASON+=	"Unknown value for ${RUBY_VERSION_REQD}"
.  endif
.else
.  if ${RUBY_VERSION_DEFAULT} == "1.8"
RUBY_VERSION?=		${RUBY18_VERSION}
.  elif ${RUBY_VERSION_DEFAULT} == "1.9"
RUBY_VERSION?=		${RUBY19_VERSION}
.  else
RUBY_VERSION?=		${RUBY18_VERSION}
.  endif
.endif

RUBY_PATCH_LEVEL=	${RUBY${RUBY_VER}_PATCHLEVEL}

.if ${RUBY_VERSION} == ${RUBY18_VERSION}
RUBY_API_VERSION=	${RUBY18_API_VERSION}
RUBY_VERSION_SUFFIX=	${RUBY_VERSION}${RUBY_PATCH_LEVEL:S/pl/./}
RUBY_ABI_VERSION=	${RUBY_VERSION_SUFFIX}
.elif ${RUBY_VERSION} == ${RUBY19_VERSION}
RUBY_API_VERSION=	${RUBY19_API_VERSION}
RUBY_VERSION_SUFFIX=	${RUBY_VERSION}${RUBY_PATCH_LEVEL}
RUBY_ABI_VERSION=	${RUBY19_API_VERSION}
.endif

#
# Variable assignment for multi-ruby packages
MULTI+=	RUBY_VERSION_REQD=${RUBY_VERSION_REQD:U${_RUBY_VERSION_DEFAULT}}

# RUBY_VERSION_SUPPORTED defines the list of ${RUBY_VER} which is
#	supported by the package.  It should be defined by the packages
#	for specific Ruby versions.
#
RUBY_VERSION_SUPPORTED?= 18 19

# RUBY_VERSION_LIST defines the list of ${RUBY_VER} which is known to
#	this framework.
#
RUBY_VERSION_LIST= 18 19

# RUBY_NOVERSION should be set to "Yes" if the package dosen't depend on
#	any specific version of ruby command.  In this case, package's
#	name begin with "ruby-".
#	If RUBY_NOVERSION is "No" (default), the package's name is begin
#	with ${RUBY_NAME}; "ruby18", "ruby19",  and so on.
#
#	It also affects to RUBY_DOC, RUBY_EG...
#
RUBY_NOVERSION?=	No

# _RUBY_VER_MAJOR, _RUBY_VER_MINOR, _RUBY_VER_TEENY and _RUBY_PATCHLEVEL
# is defined from version of Ruby.  It should not be used in packages'
# Makefile.
#
_RUBY_VER=		${RUBY_VERSION:C/(-.*)//}
_RUBY_VER_MAJOR=	${_RUBY_VER:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
_RUBY_VER_MINOR=	${_RUBY_VER:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
_RUBY_VER_TEENY=	${_RUBY_VER:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\3/}

# RUBY_VER defines Ruby base release.
#
RUBY_VER=		${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}

# RUBY_API_TEENY is used by shared library version after Ruby 1.9.1
#
.if ${RUBY_VER} == "19"
RUBY_API_TEENY=		1
.else
RUBY_API_TEENY=		${_RUBY_VER_TEENY}
.endif

# RUBY_REQD		Minimum required Ruby's version
#
RUBY_REQD?=		${RUBY_VERSION}

# RUBY_SUFFIX is appended to Ruby's commands; ruby, irb and so on.
#
RUBY_SUFFIX?=		${RUBY_VER}

# RUBY_NAME defines executable's name of Ruby itself.
#
RUBY_NAME?=		ruby${RUBY_SUFFIX}

# Optional encoding argument for shbang line
RUBY_ENCODING_ARG?=

# Name of gem and rake command
RUBYGEM_NAME=		gem${RUBY_SUFFIX}
RAKE_NAME=		rake${RUBY_SUFFIX}

# RUBY_BASE is base of ruby package's name
#
RUBY_BASE=		ruby${RUBY_VER}-base

# RUBY_PKGPREFIX is prefix part for ruby based packages.
#
RUBY_PKGPREFIX?=	${RUBY_NAME}

# RUBY_VER_DIR is used as part of  Ruby's library directories.
#
#.if ${RUBY_VER} == "18"
RUBY_VER_DIR?=		${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}
#.else
#RUBY_VER_DIR?=		${RUBY_VERSION}
#.endif

RUBY_SITE_SUBDIR?=	${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}

# Simple check for package availability with Ruby's version.
#
.if empty(RUBY_VERSION_SUPPORTED:M${RUBY_VER})
PKG_FAIL_REASON+= "This package isn't supported by ${RUBY_NAME}."
.endif

# RUBY_NOVERSION specifies that package dosen't depends on any
# version of Ruby.
#
.if empty(RUBY_NOVERSION:M[nN][oO])
RUBY_SUFFIX=
RUBY_NAME=		ruby
.endif

# Build rdoc
RUBY_BUILD_RDOC?=	YES

# Build ri, index for ri command
RUBY_BUILD_RI?=		YES

# RUBY related command's full pathname.
#
RUBY?=			${PREFIX}/bin/${RUBY_NAME}
RDOC?=			${PREFIX}/bin/rdoc${RUBY_VER}

#
# RUBY_ARCH is used as architecture-dependent directory name.
#
RUBY_ARCH?= ${LOWER_ARCH}-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}

#
# Ruby shared and static library version handling.
#
RUBY_SHLIBVER?=		${RUBY_API_VERSION}
RUBY_SHLIB?=		${RUBY_VER}.${RUBY_SLEXT}.${RUBY_SHLIBVER}
RUBY_SHLIBALIAS?=	@comment
RUBY_STATICLIB?=	${RUBY_VER}-static.a

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Interix"
RUBY_SHLIBVER=		${RUBY_VER}.${RUBY_API_TEENY}
_RUBY_SHLIBALIAS=	${RUBY_VER}.${RUBY_SLEXT}.${RUBY_VER}
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
RUBY_SHLIBVER=		${RUBY_VER}
.elif ${OPSYS} == "OpenBSD"
RUBY_SHLIBVER=		${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}${RUBY_API_TEENY}
.elif ${OPSYS} == "Darwin"
RUBY_SHLIB=		${RUBY_VER}.${RUBY_SHLIBVER}.${RUBY_SLEXT}
.if ${RUBY_VER} == "18"
_RUBY_SHLIBALIAS=	${RUBY_VER}.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}.${RUBY_SLEXT}
.else
_RUBY_SHLIBALIAS=	.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}.${RUBY_SLEXT}
RUBY_STATICLIB=		${RUBY_VER}.${RUBY_API_VERSION}-static.a
.endif
.elif ${OPSYS} == "Linux"
_RUBY_SHLIBALIAS=	${RUBY_VER}.${RUBY_SLEXT}.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}
.elif ${OPSYS} == "SunOS"
RUBY_SHLIBVER=		${_RUBY_VER_MAJOR}
 _RUBY_SHLIBALIAS=	${RUBY_VER}.${RUBY_SLEXT}.${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}.${RUBY_API_TEENY}
.endif

.if !empty(_RUBY_SHLIBALIAS)
RUBY_SHLIBALIAS=	lib/libruby${_RUBY_SHLIBALIAS}
.endif

#
# RUBY_DLEXT is suffix of extention library.
# RUBY_SLEXT is suffix of shared library.
#
.if ${OPSYS} == "Darwin"
RUBY_DLEXT=	bundle
RUBY_SLEXT=	dylib
.else
RUBY_DLEXT=	so
RUBY_SLEXT=	so
.endif

#
# Use pthread library with Ruby
#
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-9].*)
RUBY_USE_PTHREAD?=	no
.elif !empty(MACHINE_PLATFORM:MDarwin-9.*-powerpc)
# Workaround for Ruby Bug #193
# http://redmine.ruby-lang.org/issues/show/193
RUBY_USE_PTHREAD?=	no
.else
RUBY_USE_PTHREAD?=	yes
PTHREAD_OPTS+=		native
PTHREAD_AUTO_VARS=	yes
.endif

#
# Dynamic PLIST directories
#
RUBY_DYNAMIC_DIRS?=	# empty

#
# source directory
#
RUBY_SRCDIR?=	${_PKGSRC_TOPDIR}/lang/${RUBY_BASE}

#
# common paths
#
RUBY_INC=		include/ruby-${RUBY_VER_DIR}
RUBY_ARCHINC=		${RUBY_INC}/${RUBY_ARCH}
RUBY_LIB_BASE=		lib/ruby
RUBY_LIB?=		${RUBY_LIB_BASE}/${RUBY_VER_DIR}
RUBY_ARCHLIB?=		${RUBY_LIB}/${RUBY_ARCH}
RUBY_SITELIB_BASE?=	${RUBY_LIB_BASE}/site_ruby
RUBY_SITELIB?=		${RUBY_SITELIB_BASE}/${RUBY_VER_DIR}
RUBY_SITEARCHLIB?=	${RUBY_SITELIB}/${RUBY_ARCH}
RUBY_VENDORLIB_BASE?=	${RUBY_LIB_BASE}/vendor_ruby
RUBY_VENDORLIB?=	${RUBY_VENDORLIB_BASE}/${RUBY_VER_DIR}
RUBY_VENDORARCHLIB?=	${RUBY_VENDORLIB}/${RUBY_ARCH}

RUBY_DOC?=		share/doc/${RUBY_NAME}
RUBY_EG?=		share/examples/${RUBY_NAME}

# RUBY_GEM_BASE
#	The base path of the gem repository.
#
RUBY_GEM_BASE?=		${RUBY_LIB_BASE}/gems

# GEM_HOME
#	The path of the gem repository.
#
GEM_HOME?=		${RUBY_GEM_BASE}/${RUBY_VER_DIR}

#
# ri database relative path
#
RUBY_RIDIR?=		share/ri
RUBY_BASERIDIR?=	${RUBY_RIDIR}/${RUBY_VER_DIR}
RUBY_SYSRIDIR?=		${RUBY_BASERIDIR}/system
RUBY_SITERIDIR?=	${RUBY_BASERIDIR}/site

#
# MAKE_ENV
#
MAKE_ENV+=		RUBY=${RUBY:Q} RUBY_VER=${RUBY_VER:Q} \
			RUBY_VERSION=${RUBY_VERSION:Q} \
			RUBY_VERSION_DEFAULT=${RUBY_VERSION_DEFAULT:Q}

MAKEFLAGS+=		RUBY_VERSION=${RUBY_VERSION:Q} \
			RUBY_VERSION_DEFAULT=${RUBY_VERSION_DEFAULT:Q}

#
# PLIST
#
PLIST_VARS+=		ruby18 ruby19
.if ${RUBY_VER} == "18"
PLIST.ruby18=		yes
.elif ${RUBY_VER} == "19"
PLIST.ruby19=		yes
.endif

PLIST_RUBY_DIRS=	RUBY_INC=${RUBY_INC:Q} RUBY_ARCHINC=${RUBY_ARCHINC:Q} \
			RUBY_LIB_BASE=${RUBY_LIB_BASE:Q} \
			RUBY_LIB=${RUBY_LIB:Q} \
			RUBY_ARCHLIB=${RUBY_ARCHLIB:Q} \
			RUBY_SITELIB_BASE=${RUBY_SITELIB_BASE:Q} \
			RUBY_SITELIB=${RUBY_SITELIB:Q} \
			RUBY_SITEARCHLIB=${RUBY_SITEARCHLIB:Q} \
			RUBY_VENDORLIB_BASE=${RUBY_VENDORLIB_BASE:Q} \
			RUBY_VENDORLIB=${RUBY_VENDORLIB:Q} \
			RUBY_VENDORARCHLIB=${RUBY_VENDORARCHLIB:Q} \
			RUBY_DOC=${RUBY_DOC:Q} \
			RUBY_EG=${RUBY_EG:Q} \
			RUBY_GEM_BASE=${RUBY_GEM_BASE:Q} \
			GEM_HOME=${GEM_HOME:Q} \
			RUBY_RIDIR=${RUBY_RIDIR:Q} \
			RUBY_BASERIDIR=${RUBY_BASERIDIR:Q} \
			RUBY_SYSRIDIR=${RUBY_SYSRIDIR:Q} \
			RUBY_SITERIDIR=${RUBY_SITERIDIR:Q}

#
# substitutions
#
FILES_SUBST+=		RUBY=${RUBY:Q} RUBY_NAME=${RUBY_NAME:Q} \
			RUBY_PKGPREFIX=${RUBY_PKGPREFIX:Q} \
			RUBY_VER=${RUBY_VER:Q} \
			${PLIST_RUBY_DIRS}

MESSAGE_SUBST+=		RUBY="${RUBY}" RUBY_VER="${RUBY_VER}" \
			RUBY_VERSION="${RUBY_VERSION}" \
			RUBY_PKGPREFIX="${RUBY_PKGPREFIX}" \
			${PLIST_RUBY_DIRS:S,DIR="${PREFIX}/,DIR=",}

PLIST_SUBST+=		RUBY=${RUBY:Q} RUBY_VER=${RUBY_VER:Q} \
			RUBY_PKGPREFIX=${RUBY_PKGPREFIX} \
			RUBY_VERSION=${RUBY_VERSION:Q} \
			RUBY_VER_DIR=${RUBY_VER_DIR:Q} \
			RUBY_DLEXT=${RUBY_DLEXT:Q} RUBY_SLEXT=${RUBY_SLEXT:Q} \
			RUBY_SHLIB=${RUBY_SHLIB:Q} \
			RUBY_SHLIBALIAS=${RUBY_SHLIBALIAS:Q} \
			RUBY_STATICLIB=${RUBY_STATICLIB:Q} \
			RUBY_ARCH=${RUBY_ARCH:Q} \
			${PLIST_RUBY_DIRS:S,DIR="${PREFIX}/,DIR=",}

#
# make dynamic PLIST
#
.if !empty(RUBY_DYNAMIC_DIRS)

RUBY_PLIST_DYNAMIC=	${WRKDIR}/PLIST.work

.if !defined(PLIST_SRC)
.  if exists(${PKGDIR}/PLIST.common)
PLIST_SRC+=		${PKGDIR}/PLIST.common
.  elif exists(${PKGDIR}/PLIST)
PLIST_SRC+=		${PKGDIR}/PLIST
.  endif

PLIST_SRC+=		${RUBY_PLIST_DYNAMIC}

.  if exists(${PKGDIR}/PLIST.common_end)
PLIST_SRC+=		${PKGDIR}/PLIST.common_end
.  endif

.endif

RUBY_PLIST_COMMENT_CMD= \
	${ECHO} "@comment The following lines are automatically generated"
RUBY_PLIST_FILES_CMD= ( cd ${DESTDIR}${PREFIX}; \
	${FIND} ${RUBY_DYNAMIC_DIRS} \( -type f -o -type l \) -print ) | \
	${SORT} -u
RUBY_GENERATE_PLIST =	( \
	${RUBY_PLIST_COMMENT_CMD}; \
	${RUBY_PLIST_FILES_CMD} ) > ${RUBY_PLIST_DYNAMIC}
.endif

.if !empty(RUBY_NOVERSION:M[nN][oO])
.if empty(RUBY_USE_PTHREAD:M[nN][oO])
.include "../../mk/pthread.buildlink3.mk"
.endif
.include "../../mk/bdb.buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../security/openssl/buildlink3.mk"
.include "../../mk/dlopen.buildlink3.mk"
.endif

PRINT_PLIST_AWK+=	/lib\/libruby${RUBY_STATICLIB}$$/ \
			{ sub(/${RUBY_STATICLIB}/, "$${RUBY_STATICLIB}"); }
PRINT_PLIST_AWK+=	/lib\/libruby${RUBY_VER}\.${RUBY_SLEXT}/ \
			{ sub(/${RUBY_VER}\.${RUBY_SLEXT}$$/, \
			"$${RUBY_VER}.$${RUBY_SLEXT}"); }
PRINT_PLIST_AWK+=	/${RUBY_SHLIB}$$/ \
			{ sub(/${RUBY_SHLIB}$$/, "$${RUBY_SHLIB}"); }
PRINT_PLIST_AWK+=	/${RUBY_SLEXT}\.${RUBY_SHLIBVER}$$/ \
			{ sub(/${RUBY_SLEXT}\.${RUBY_SHLIBVER}$$/, \
			"$${RUBY_SLEXT}.$${RUBY_SHLIBVER}"); }
.if ${RUBY_SHLIBALIAS} != "@comment"
PRINT_PLIST_AWK+=	/${RUBY_SHLIBALIAS:S/\//\\\//}$$/ \
			{ sub(/${RUBY_SHLIBALIAS:S/\//\\\//}$$/, \
			"$${RUBY_SHLIBALIAS}"); }
.endif
PRINT_PLIST_AWK+=	/^${RUBY_ARCHINC:S|/|\\/|g}/ \
			{ gsub(/${RUBY_ARCHINC:S|/|\\/|g}/, "$${RUBY_ARCHINC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_INC:S|/|\\/|g}/ \
			{ gsub(/${RUBY_INC:S|/|\\/|g}/, "$${RUBY_INC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/\.${RUBY_DLEXT}$$/ \
			{ gsub(/${RUBY_DLEXT}$$/, "$${RUBY_DLEXT}") }
PRINT_PLIST_AWK+=	/^${RUBY_ARCHLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_ARCHLIB:S|/|\\/|g}/, "$${RUBY_ARCHLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_VENDORARCHLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_VENDORARCHLIB:S|/|\\/|g}/, "$${RUBY_VENDORARCHLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_VENDORLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_VENDORLIB:S|/|\\/|g}/, "$${RUBY_VENDORLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITEARCHLIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITEARCHLIB:S|/|\\/|g}/, "$${RUBY_SITEARCHLIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITELIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITELIB:S|/|\\/|g}/, "$${RUBY_SITELIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITELIB_BASE:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITELIB_BASE:S|/|\\/|g}/, "$${RUBY_SITELIB_BASE}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_VENDORLIB_BASE:S|/|\\/|g}/ \
			{ gsub(/${RUBY_VENDORLIB_BASE:S|/|\\/|g}/, "$${RUBY_VENDORLIB_BASE}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_LIB:S|/|\\/|g}/ \
			{ gsub(/${RUBY_LIB:S|/|\\/|g}/, "$${RUBY_LIB}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_DOC:S|/|\\/|g}/ \
			{ gsub(/${RUBY_DOC:S|/|\\/|g}/, "$${RUBY_DOC}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_EG:S|/|\\/|g}/ \
			{ gsub(/${RUBY_EG:S|/|\\/|g}/, "$${RUBY_EG}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SITERIDIR:S|/|\\/|g}/ \
			{ gsub(/${RUBY_SITERIDIR:S|/|\\/|g}/, "$${RUBY_SITERIDIR}"); \
			print; next; }
PRINT_PLIST_AWK+=	/^${RUBY_SYSRIDIR:S|/|\\/|g}\// \
			{ next; }
PRINT_PLIST_AWK+=	/\/${RUBY_NAME}/ \
			{ sub(/${RUBY_NAME}/, "$${RUBY_NAME}"); }

.endif # _RUBY_MK
