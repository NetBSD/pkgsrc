# $NetBSD: x11.buildlink3.mk,v 1.3 2005/07/31 23:54:04 rillig Exp $
#
# This Makefile fragment is meant to be included by packages that
# require an X11 distribution.  x11.buildlink3.mk will include the
# buildlink3.mk file from the appropriate X11 distribution.
#

X11_BUILDLINK3_MK:=	${X11_BUILDLINK3_MK}+

.include "../../mk/bsd.prefs.mk"

.if !empty(X11_BUILDLINK3_MK:M+)
USE_X11=	yes

.  include "../../mk/x11.version.mk"

.  if defined(GNU_CONFIGURE)
# XXX when X11BASE is quoted using :Q here, audio/bmp does not build
# XXX because the $ disappears, leaving {DESTDIR}/usr/X11R6/include.
# XXX Can someone please explain this?
CONFIGURE_ARGS+=	--x-includes=${X11BASE}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE}/lib${LIBABISUFFIX:Q}
.  endif

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib${LIBABISUFFIX}
X11_LDFLAGS+=	-L${X11BASE}/lib${LIBABISUFFIX}
.endif	# X11_BUILDLINK3_MK

.sinclude "${X11_PKGSRCDIR.${X11_TYPE}}/buildlink3.mk"
