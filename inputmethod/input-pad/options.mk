# $NetBSD: options.mk,v 1.3 2010/11/30 11:20:16 obache Exp $
#

PKG_OPTIONS_VAR=	PKG_OPTIONS.input-pad
PKG_SUPPORTED_OPTIONS=	eekboard xtest
PKG_SUGGESTED_OPTIONS=	eekboard

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	eek xtest

#
# Draw keyboard using libeek
#
.if !empty(PKG_OPTIONS:Meekboard)
.include "../../x11/eekboard/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-eek
PLIST.eek=		yes
.endif

#
# Send keyboard event with xtest
#
.if !empty(PKG_OPTIONS:Mxtest)
.include "../../x11/libXtst/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-xtest=yes
PLIST.xtest=		yes
.endif
