# $NetBSD: x11.buildlink.mk,v 1.13 2001/12/08 23:17:18 kristerw Exp $
#
# This Makefile fragment is included by packages that use X11.
#
# To use this Makefile fragment, simply:
#
# (1) Optionally define USE_BUILDLINK_X11 to use pkgtools/buildlink-x11
#     to cause packages that use imake to use buildlink, and
# (2) Include this Makefile fragment in the package Makefile.
#
# NOTE: This file must be included _before_ bsd.pkg.mk.
# NOTE: This file should _not_ be included in any package's buildlink.mk file.

.if !defined(X11_BUILDLINK_MK)
X11_BUILDLINK_MK=	# defined

# A package that includes this file _must_ be satisfying the requirements
# for at least USE_X11, and often for USE_X11BASE.
#
USE_X11=		# defined

.include "../../mk/bsd.buildlink.mk"

BUILD_DEPENDS+=		x11-links>=0.5:../../pkgtools/x11-links
BUILDLINK_X11_DIR?=	${LOCALBASE}/share/x11-links
CONFIGURE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"
MAKE_ENV+=		BUILDLINK_X11_DIR="${BUILDLINK_X11_DIR}"

.if !defined(_BUILDLINK_X11_CPPFLAGS) || !defined(_BUILDLINK_X11_LDFLAGS)
_BUILDLINK_X11_CPPFLAGS=	-I${BUILDLINK_X11_DIR}/include
_BUILDLINK_X11_LDFLAGS=		-L${BUILDLINK_X11_DIR}/lib -Wl,-R${X11BASE}/lib

# We just append to these values, as there's no need for the BUILDLINK_X11
# flags to be listed in the beginning; these are just the X11R6 headers and
# libraries and they're often specified last.
#
CFLAGS+=		${_BUILDLINK_X11_CPPFLAGS}
CXXFLAGS+=		${_BUILDLINK_X11_CPPFLAGS}
CPPFLAGS+=		${_BUILDLINK_X11_CPPFLAGS}
LDFLAGS+=		${_BUILDLINK_X11_LDFLAGS}
.endif

# Tell packages that use GNU configure where to find the X11R6 headers and
# libraries.
#
.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--x-includes=${BUILDLINK_X11_DIR}/include
CONFIGURE_ARGS+=	--x-libraries=${BUILDLINK_X11_DIR}/lib
.endif

# Separate out optional code to use buildlink-x11, which causes packages
# that use imake to use buildlink.  If USE_BUILDLINK_X11 is defined, then
# X11 packages will need to be patched to replace any hard-coded instances
# of /usr/X11R6 with ${BUILDLINK_X11_DIR} in the library search path.
#
# Note:	The use of this code is _untested_ and not recommended.  Packages
#	have not been modified to satisfy the assumptions used by
#	buildlink-x11 yet, and using this code will likely cause pkgsrc to
#	break.
#
.if defined(USE_BUILDLINK_X11)
BUILD_DEPENDS+=		buildlink-x11>=0.8:../../pkgtools/buildlink-x11
MAKE_ENV+=		PKGSRC_CPPFLAGS="${CPPFLAGS}"
MAKE_ENV+=		PKGSRC_CFLAGS="${CFLAGS}"
MAKE_ENV+=		PKGSRC_CXXFLAGS="${CXXFLAGS}"
MAKE_ENV+=		PKGSRC_LDFLAGS="${LDFLAGS}"
XMKMF_CMD?=		${X11PREFIX}/bin/buildlink-xmkmf
.if defined(USE_BUILDLINK_ONLY)
XMKMF_FLAGS+=		-DBuildLink
XMKMF_FLAGS+=		-DBuildLinkX11
.endif
.endif

# Make the appropriate substitutions for ${X11BASE} <--> ${BUILDLINK_X11_DIR}.
# We append to *_POST_SED so these substitutions come after any other
# package's *_SED substitutions.
#
_BUILDLINK_CONFIG_WRAPPER_POST_SED+=					\
	-e "s|-I${X11BASE}/|-I${BUILDLINK_X11_DIR}/|g"			\
	-e "s|-L${X11BASE}/|-L${BUILDLINK_X11_DIR}/|g"

_REPLACE_BUILDLINK_POST_SED+=						\
	-e "s|-I${BUILDLINK_X11_DIR}/|-I${X11BASE}/|g"			\
	-e "s|-L${BUILDLINK_X11_DIR}/|-L${X11BASE}/|g"

REPLACE_RPATH_SED+=	\
	-e "s|-R[ 	]*${BUILDLINK_X11_DIR}/|-R${X11BASE}/|g"

.endif	# X11_BUILDLINK_MK
