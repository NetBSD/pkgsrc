# $NetBSD: options.mk,v 1.14 2020/04/11 21:09:23 khorben Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.gtk-vnc
PKG_SUPPORTED_OPTIONS=	python vnc-sasl pulseaudio
PKG_SUGGESTED_OPTIONS=	python vnc-sasl pulseaudio

.include "../../mk/bsd.options.mk"

PLIST_VARS=	python
.if !empty(PKG_OPTIONS:Mpython)
PYTHON_VERSIONS_ACCEPTED=	  27 # py-gtk2
.include "../../lang/python/extension.mk"
.include "../../x11/py-gtk2/buildlink3.mk"
PLIST.python=	yes
CONFIGURE_ARGS+=	--with-python
.else
CONFIGURE_ARGS+=	--without-python
.endif

.if !empty(PKG_OPTIONS:Mvnc-sasl)
.include "../../security/cyrus-sasl/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--without-sasl
.endif

PLIST_VARS+=	pulseaudio
.if !empty(PKG_OPTIONS:Mpulseaudio)
.include "../../audio/pulseaudio/buildlink3.mk"
CONFIGURE_ARGS+=	--with-pulseaudio
PLIST.pulseaudio=	yes
.else
CONFIGURE_ARGS+=	--without-pulseaudio
.endif
