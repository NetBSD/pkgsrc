# $NetBSD: options.mk,v 1.2 2010/02/19 08:33:28 schmonz Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.pari
PKG_SUPPORTED_OPTIONS=	gmp x11
PKG_SUGGESTED_OPTIONS=	gmp

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		nogmp gmp

.if !empty(PKG_OPTIONS:Mgmp)
PLIST.gmp=		yes

CONFIGURE_ARGS+=	--with-gmp=${PREFIX:Q}

.include "../../devel/gmp/buildlink3.mk"
.else
PLIST.nogmp=		yes
.endif

.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--graphic=X11
CONFIGURE_ARGS+=	--with-fltk=${PREFIX:Q}
CONFIGURE_ENV+=		X11BASE=${X11BASE:Q}
CONFIGURE_ENV+=		Xincroot=${X11BASE}/include
.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/fltk/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--graphic=none
# don't let the configure script find an installed fltk
CONFIGURE_ARGS+=	--with-fltk={BUILDLINK_DIR:Q}/nonexistent
.endif
