# $NetBSD: options.mk,v 1.5 2008/11/24 04:06:00 smb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.memtestplus
PKG_SUPPORTED_OPTIONS=	iso serialconsole
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=		iso
.if !empty(PKG_OPTIONS:Miso)
BUILD_TARGET=		iso
BUILD_DEPENDS+=		{cdrtools,cdrtools-ossdvd}>=2.01:../../sysutils/cdrtools
PLIST.iso=		yes
.endif

.if !empty(PKG_OPTIONS:Mserialconsole)
SUBST_CLASSES+=		serialopt
SUBST_STAGE.serialopt=	post-patch
SUBST_MESSAGE.serialopt=	Setting serial console option
SUBST_FILES.serialopt=	config.h
SUBST_SED.serialopt=	-e '/define.*SERIAL_CONSOLE_DEFAULT/s/0/1/'
.endif
