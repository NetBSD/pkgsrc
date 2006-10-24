# $NetBSD: options.mk,v 1.1 2006/10/24 18:00:05 smb Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.memtestplus
PKG_SUPPORTED_OPTIONS=	memtesplus-iso memtesplus-serialconsole
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mmemtesplus-iso)
BUILD_TARGET=		memtest.iso
BUILD_DEPENDS+=		cdrtools>=2.01:../../sysutils/cdrtools
PLIST_SUBST+=		HAVE_ISO=""
.else
PLIST_SUBST+=		HAVE_ISO="@comment "
.endif

.if !empty(PKG_OPTIONS:Mmemtesplus-serialconsole)
SUBST_CLASSES+=		serialopt
SUBST_STAGE.serialopt=	post-patch
SUBST_MESSAGE.serialopt=	Setting serial console option
SUBST_FILES.serialopt=	config.h
SUBST_SED.serialopt=	-e '/define.*SERIAL_CONSOLE_DEFAULT/s/0/1/'
.endif
