# $NetBSD: options.mk,v 1.2 2010/06/01 21:55:32 markd Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.squeak-vm
PKG_SUPPORTED_OPTIONS=		nas pulseaudio
PKG_SUGGESTED_OPTIONS=		nas

.include "../../mk/bsd.options.mk"

PLIST_VARS=	nas pulse

.if !empty(PKG_OPTIONS:Mnas)
PLIST.nas=	yes
.include "../../audio/nas/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpulseaudio)
PLIST.pulse=	yes
.include "../../audio/pulseaudio/buildlink3.mk"
.endif
