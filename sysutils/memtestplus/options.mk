# $NetBSD: options.mk,v 1.3 2007/12/30 18:40:52 mlelstv Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.memtestplus
PKG_SUPPORTED_OPTIONS=	iso serialconsole
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Miso)
BUILD_TARGET=		memtest.iso
BUILD_DEPENDS+=		{cdrtools,cdrtools-ossdvd}>=2.01:../../sysutils/cdrtools
PLIST_SUBST+=		HAVE_ISO=""
.else
PLIST_SUBST+=		HAVE_ISO="@comment "
.endif

.if !empty(PKG_OPTIONS:Mserialconsole)
SUBST_CLASSES+=		serialopt
SUBST_STAGE.serialopt=	post-patch
SUBST_MESSAGE.serialopt=	Setting serial console option
SUBST_FILES.serialopt=	config.h
SUBST_SED.serialopt=	-e '/define.*SERIAL_CONSOLE_DEFAULT/s/0/1/'
.endif
