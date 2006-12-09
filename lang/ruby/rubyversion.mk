# $NetBSD: rubyversion.mk,v 1.27.2.2 2006/12/09 10:17:47 salo Exp $
#

.if !defined(_RUBYVERSION_MK)
_RUBYVERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# current supported Ruby's version
RUBY18_VERSION=		1.8.5

# patch date
RUBY18_PATCH_DATE=	20061205

# RUBY_VERSION_DEFAULT defines default version for Ruby related
#	packages and user can define in mk.conf.  (1.6 or 1.8)
#
RUBY_VERSION_DEFAULT?=	1.8

# RUBY_VERSION defines the specific Ruby's version which is supported
#	by the package.  It should be defined by packages whose distfiles
#	are contained by Ruby's release distribution.
#
#	Default value is set to ${RUBY_VERSION_DEFAULT}
#
.if ${RUBY_VERSION_DEFAULT} == "1.8"
RUBY_VERSION?=		${RUBY18_VERSION}
RUBY_PATCH_DATE?=	${RUBY18_PATCH_DATE}
.endif

RUBY_VERSION_SUFFIX=	${RUBY_VERSION}.${RUBY_PATCH_DATE}

# RUBY_VERSION_SUPPORTED defines the list of ${RUBY_VER} which is
#	supported by the package.  It should be defined by the packages
#	for specific Ruby versions.
#
RUBY_VERSION_SUPPORTED?= 18

# RUBY_VERSION_LIST defines the list of ${RUBY_VER} which is known to
#	this framework.
#
RUBY_VERSION_LIST= 18

# RUBY_NOVERSION should be set to "Yes" if the package dosen't depend on
#	any specific version of ruby command.  In this case, package's
#	name begin with "ruby-".
#	If RUBY_NOVERSION is "No" (default), the package's name is begin
#	with ${RUBY_NAME}; "ruby18", "ruby19",  and so on.
#
#	It also affects to RUBY_DOCDIR, RUBY_EXAMPLESDIR...
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
_RUBY_PATCHLEVEL=	${RUBY_VERSION:C/(.*-)//}

# RUBY_VER defines Ruby base release.
#
RUBY_VER=		${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}

#
# RUBY_HAS_ARCHLIB	This package contains machine dependent binaries.
# RUBY_REQD		Minimum required Ruby's version
#
.if defined(RUBY_HAS_ARCHLIB) && empty(RUBY_HAS_ARCHLIB:M[nN][oO])
.if ${RUBY_VER} == "18"
RUBY_REQD?=		${RUBY18_VERSION}
.endif
.else
.if ${RUBY_VER} == "18"
RUBY_REQD?=		1.8.1
.endif
.endif

# RUBY_SUFFIX is appended to Ruby's commands; ruby, irb and so on.
#
RUBY_SUFFIX?=		${RUBY_VER}

# RUBY_NAME defines executable's name of Ruby itself.
#
RUBY_NAME?=		ruby${RUBY_SUFFIX}

# RUBY_BASE is base of ruby package's name
#
RUBY_BASE=		ruby${RUBY_VER}-base

# RUBY_PKGPREFIX is prefix part for ruby based packages.
#
RUBY_PKGPREFIX?=	${RUBY_NAME}

# RUBY_VER_DIR is used as part of  Ruby's library directories.
#
RUBY_VER_DIR?=		${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}

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

# RUBY related command's full pathname.
#
RUBY?=			${PREFIX}/bin/${RUBY_NAME}
RDOC?=			${PREFIX}/bin/rdoc${RUBY_VER}

#
# RUBY_ARCH is used as architecture-dependent directory name.
#
RUBY_ARCH?= ${LOWER_ARCH}-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}

#
# Ruby shared library version handling.
#
RUBY_SHLIBMAJOR?=	${_RUBY_VER_MAJOR}
RUBY_SHLIBVER?=		${RUBY_VERSION}

.if ${OPSYS} == "NetBSD" || ${OPSYS} == "Interix"
RUBY_SHLIBMAJOR=	${RUBY_VER}
RUBY_SHLIBVER=		${RUBY_VER}.${_RUBY_VER_TEENY}
.elif ${OPSYS} == "FreeBSD" || ${OPSYS} == "DragonFly"
RUBY_SHLIBMAJOR=	# unused
RUBY_SHLIBVER=		${RUBY_VER}
.elif ${OPSYS} == "OpenBSD"
RUBY_SHLIBMAJOR=	# unused
RUBY_SHLIBVER=		${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}${_RUBY_VER_TEENY}
.elif ${OPSYS} == "IRIX"
RUBY_SHLIBMAJOR=	# unused
.elif ${OPSYS} == "Linux"
RUBY_SHLIBMAJOR=	${_RUBY_VER_MAJOR}.${_RUBY_VER_MINOR}
.endif

.if empty(RUBY_SHLIBMAJOR)
RUBY_NOSHLIBMAJOR=	"@comment "
.else
RUBY_NOSHLIBMAJOR=
.endif


#
# RUBY_DLEXT is suffix of extention library.
#
.if ${OPSYS} == "Darwin"
RUBY_DLEXT=	bundle
.else
RUBY_DLEXT=	so
.endif

#
# Use pthread library with Ruby
#
.if ${OPSYS} == "NetBSD" && !empty(OS_VERSION:M1.[0-9].*)
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
RUBY_LIBDIR?=		${PREFIX}/lib/ruby/${RUBY_VER_DIR}
RUBY_ARCHLIBDIR?=	${RUBY_LIBDIR}/${RUBY_ARCH}
RUBY_SITELIBDIR?=	${PREFIX}/lib/ruby/site_ruby/${RUBY_VER_DIR}
RUBY_SITEARCHLIBDIR?=	${RUBY_SITELIBDIR}/${RUBY_ARCH}
RUBY_DOCDIR?=		${PREFIX}/share/doc/${RUBY_NAME}
RUBY_EXAMPLESDIR?=	${PREFIX}/share/examples/${RUBY_NAME}
RUBY_RIDIR?=		${PREFIX}/share/ri
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

# PLIST
#
PLIST_RUBY_DIRS=	RUBY_LIBDIR="${RUBY_LIBDIR}" \
			RUBY_ARCHLIBDIR="${RUBY_ARCHLIBDIR}" \
			RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" \
			RUBY_SITEARCHLIBDIR="${RUBY_SITEARCHLIBDIR}" \
			RUBY_DOCDIR="${RUBY_DOCDIR}" \
			RUBY_EXAMPLESDIR="${RUBY_EXAMPLESDIR}" \
			RUBY_RIDIR="${RUBY_RIDIR}" \
			RUBY_BASERIDIR="${RUBY_BASERIDIR}" \
			RUBY_SYSRIDIR="${RUBY_SYSRIDIR}" \
			RUBY_SITERIDIR="${RUBY_SITERIDIR}"

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
			RUBY_VERSION=${RUBY_VERSION:Q} \
			RUBY_VER_DIR=${RUBY_VER_DIR:Q} \
			RUBY_DLEXT=${RUBY_DLEXT:Q} \
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
RUBY_PLIST_FILES_CMD= ( cd ${PREFIX}; \
	${FIND} ${RUBY_DYNAMIC_DIRS} \( -type f -o -type l \) -print ) | \
	${SORT} -u
RUBY_PLIST_DIRS_CMD= ( cd ${PREFIX}; \
	${FIND} ${RUBY_DYNAMIC_DIRS} -type d -print ) | ${SORT} -ru | \
	${SED} -e 's|^|@dirrm |'
RUBY_GENERATE_PLIST =	( \
	${RUBY_PLIST_COMMENT_CMD}; \
	${RUBY_PLIST_FILES_CMD}; \
	${RUBY_PLIST_DIRS_CMD} ) > ${RUBY_PLIST_DYNAMIC}
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

.endif # _RUBY_MK
