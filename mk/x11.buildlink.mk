# $NetBSD: x11.buildlink.mk,v 1.17.2.2 2002/08/21 22:01:35 jlam Exp $
#
# This Makefile fragment is included by packages that use X11.  It's
# only purpose is to make a package strongly buildlinked, so packages
# that include this file must already satisfy the requirements for
# USE_BUILDLINK_ONLY.
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

BUILD_DEPENDS+=		x11-links>=0.6:../../pkgtools/x11-links
BUILDLINK_X11_DIR=	${LOCALBASE}/share/x11-links
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

# Make the appropriate substitutions for ${X11BASE} <--> ${BUILDLINK_X11_DIR}.
# We append to *_POST_SED so these substitutions come after any other
# package's *_SED substitutions.
#
_BUILDLINK_CONFIG_WRAPPER_POST_SED+=					\
	-e "s|-I${X11BASE}/|-I${BUILDLINK_X11_DIR}/|g"			\
	-e "s|-L${X11BASE}/|-L${BUILDLINK_X11_DIR}/|g"

_REPLACE_BUILDLINK_POST_SED+=						\
	-e "s|${BUILDLINK_X11_DIR}|${X11BASE}|g"

REPLACE_RPATH_SED+=	\
	-e "s|-R[ 	]*${BUILDLINK_X11_DIR}/|-R${X11BASE}/|g"

.endif	# X11_BUILDLINK_MK
