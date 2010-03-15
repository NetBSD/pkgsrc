# $NetBSD: options.mk,v 1.1.1.1 2010/03/15 14:08:49 asau Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.gromacs
PKG_SUPPORTED_OPTIONS+=		x11
PKG_SUGGESTED_OPTIONS+=		x11

.include "../../mk/bsd.options.mk"

PLIST_VARS=	x11

# X support:
.if !empty(PKG_OPTIONS:Mx11)
CONFIGURE_ARGS+=	--with-x
PLIST.x11=	yes

.include "../../x11/libX11/buildlink3.mk"
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.endif
