# $NetBSD: x11.buildlink3.mk,v 1.2 2005/07/28 16:20:52 jlam Exp $
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
CONFIGURE_ARGS+=	--x-includes=${X11BASE:Q}/include
CONFIGURE_ARGS+=	--x-libraries=${X11BASE:Q}/lib${LIBABISUFFIX:Q}
.  endif

X11_LDFLAGS+=	${COMPILER_RPATH_FLAG}${X11BASE}/lib${LIBABISUFFIX}
X11_LDFLAGS+=	-L${X11BASE}/lib${LIBABISUFFIX}
.endif	# X11_BUILDLINK3_MK

.sinclude "${X11_PKGSRCDIR.${X11_TYPE}}/buildlink3.mk"
