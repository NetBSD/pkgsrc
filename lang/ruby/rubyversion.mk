# $NetBSD: rubyversion.mk,v 1.9 2005/01/28 13:51:24 taca Exp $
#

.ifndef _RUBYVERSION_MK
_RUBYVERSION_MK=	# defined

.include "../../mk/bsd.prefs.mk"

# current supported Ruby's version
RUBY16_VERSION?=	1.6.8
RUBY18_VERSION?=	1.8.2

# default Ruby packages
RUBY_VER_DEFAULT=	18

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
.if !defined(RUBY_VERSION)
.if ${RUBY_VERSION_DEFAULT} == "1.6"
RUBY_VERSION?=		${RUBY16_VERSION}
.elif ${RUBY_VERSION_DEFAULT} == "1.8"
RUBY_VERSION?=		${RUBY18_VERSION}
.endif
.endif

# RUBY_VERSION_SUPPORTED defines the list of ${RUBY_VER} which is
#	supported by the package.  It should be defined by The pacakges
#	for specific version Ruby.
#
RUBY_VERSION_SUPPORTED?= 16 18

# RUBY_VERSION_LIST defines the list of ${RUBY_VER} which is known to
#	this framework.
#
RUBY_VERSION_LIST= 16,18

# RUBY_NOVERSION should be set to "Yes" if the package dosen't depend on
#	any specific version of ruby command.  In this case, package's
#	name begin with "ruby-".
#	If RUBY_NOVERSION is "No" (default), the package's name is begin
#	with ${RUBY_NAME}; "ruby16-", "ruby18" and so on.
#
#	It also affects to RUBY_DOCDIR, RUBY_EXAMPLESDIR...
#
RUBY_NOVERSION?=	No

# _RUBY_VER_MAJOR, _RUBY_VER_MINOR, _RUBY_VERS_TEENY is defined from
#	version of Ruby.  It could be used in packages' Makefile but
#	it isn't recommended.
#
_RUBY_VER_MAJOR=	${RUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\1/}
_RUBY_VER_MINOR=	${RUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\2/}
_RUBY_VERS_TEENY=	${RUBY_VERSION:C/([0-9]+)\.([0-9]+)\.([0-9]+)/\3/}

# RUBY_VER defines Ruby base release.
#
RUBY_VER=		${_RUBY_VER_MAJOR}${_RUBY_VER_MINOR}

#
# RUBY_HAS_ARCHLIB	This package contains machine dependent binaries.
# RUBY_REQD		Minimum required Ruby's version
#
.if defined(RUBY_HAS_ARCHLIB) && empty(RUBY_HAS_ARCHLIB:M[nN][oO])
.if ${RUBY_VER} == "16"
RUBY_REQD?=		${RUBY16_VERSION}
.elif ${RUBY_VER} == "18"
RUBY_REQD?=		${RUBY18_VERSION}
.endif
.else
.if ${RUBY_VER} == "16"
RUBY_REQD?=		1.6.8
.elif ${RUBY_VER} == "18"
RUBY_REQD?=		1.8.1
.endif
.endif

# RUBY_SUFFIX is appended to Ruby's commands; ruby, irb and so on.
#
RUBY_SUFFIX?=		${RUBY_VER}

# RUBY_NAME defines executable's name of Ruby itself.
#
RUBY_NAME?=		ruby${RUBY_SUFFIX}

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
RUBY?=			${LOCALBASE}/bin/${RUBY_NAME}
RDOC?=			${LOCALBASE}/bin/rdoc${RUBY_VER}

#
# RUBY_ARCH is used architecture depended direcotry name.
#
.if ${OPSYS} == "Linux" && ${RUBY_VER} == "16"
RUBY_ARCH?= ${LOWER_ARCH}-${LOWER_OPSYS}-gnu
.else
RUBY_ARCH?= ${LOWER_ARCH}-${LOWER_OPSYS}${APPEND_ELF}${LOWER_OPSYS_VERSUFFIX}
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
# common PATH
#
RUBY_LIBDIR?=		${LOCALBASE}/lib/ruby/${RUBY_VER_DIR}
RUBY_ARCHLIBDIR?=	${RUBY_LIBDIR}/${RUBY_ARCH}
RUBY_SITELIBDIR?=	${LOCALBASE}/lib/ruby/site_ruby/${RUBY_VER_DIR}
RUBY_SITEARCHLIBDIR?=	${RUBY_SITELIBDIR}/${RUBY_ARCH}
RUBY_DOCDIR?=		${LOCALBASE}/share/doc/${RUBY_NAME}
RUBY_EXAMPLESDIR?=	${LOCALBASE}/share/examples/${RUBY_NAME}

#
# make ruby based packages' distfiles to one place.
#
RUBY_DIST_SUBDIR?=	ruby

#
# MAKE_ENV
#
MAKEFLAGS+=		RUBY_VER=${RUBY_VER}

#
# PLIST
#
PLIST_RUBY_DIRS=	RUBY_LIBDIR="${RUBY_LIBDIR}" \
			RUBY_ARCHLIBDIR="${RUBY_ARCHLIBDIR}" \
			RUBY_SITELIBDIR="${RUBY_SITELIBDIR}" \
			RUBY_SITEARCHLIBDIR="${RUBY_SITEARCHLIBDIR}" \
			RUBY_DOCDIR="${RUBY_DOCDIR}" \
			RUBY_EXAMPLESDIR="${RUBY_EXAMPLESDIR}" \
			RUBY_DLEXT="${RUBY_DLEXT}"

PLIST_SUBST+=		RUBY_VER="${RUBY_VER}" \
			${PLIST_RUBY_DIRS:S,DIR="${LOCALBASE}/,DIR=",}
MESSAGE_SUBST+=		RUBY_VER="${RUBY_VER}" \
			${PLIST_RUBY_DIRS:S,DIR="${LOCALBASE}/,DIR=",}

.endif # _RUBY_MK
