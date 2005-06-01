# $NetBSD: x11.buildlink3.mk,v 1.1 2005/06/01 18:03:06 jlam Exp $
#
# This Makefile fragment is meant to be included by packages that
# require an X11 distribution.  x11.buildlink3.mk will include the
# buildlink3.mk file from the appropriate X11 distribution.
#

.include "../../mk/bsd.prefs.mk"

USE_X11=	yes

.include "../../mk/x11.version.mk"

.if defined(GNU_CONFIGURE)
CONFIGURE_ARGS+=	--x-includes=${X11BASE:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE:Q}/lib${LIBABISUFFIX:Q}
.endif

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib${LIBABISUFFIX}
X11_LDFLAGS+=	-L${X11BASE}/lib${LIBABISUFFIX}

.sinclude "${X11_PKGSRCDIR.${X11_TYPE}}/buildlink3.mk"
