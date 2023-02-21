# $NetBSD: options.mk,v 1.6 2023/02/21 17:23:07 adam Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.opensc

# Arguably these should be selectable individually, but upstream requires
# that exactly one be chosen.
PKG_OPTIONS_REQUIRED_GROUPS=	cardreader
PKG_OPTIONS_GROUP.cardreader=	pcsc-lite openct
PKG_SUGGESTED_OPTIONS=		pcsc-lite

.include "../../mk/bsd.options.mk"

.if ${OPSYS} == "Darwin"
SOEXT=	dylib
.else
SOEXT=	so
.endif

.if !empty(PKG_OPTIONS:Mpcsc-lite)
.include "../../security/pcsc-lite/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-pcsc
.  if ${OPSYS} == "Darwin" && exists(/System/Library/Frameworks/PCSC.framework)
# On Darwin, prefer system-provided PCSC.
.  else
# While one might expect the libtool .la, ltdl support has been
# removed from opensc.
CONFIGURE_ARGS+=	--with-pcsc-provider=${BUILDLINK_PREFIX.pcsc-lite}/lib/libpcsclite.${SOEXT}
.  endif
# This is perhaps an upstream bug.
CONFIGURE_ENV+=		PCSC_CFLAGS=-I${BUILDLINK_PREFIX.pcsc-lite}/include/PCSC
.else
CONFIGURE_ARGS+=	--disable-pcsc
.endif

.if !empty(PKG_OPTIONS:Mopenct)
.include "../../security/openct/buildlink3.mk"
CONFIGURE_ARGS+=	--enable-openct
.else
CONFIGURE_ARGS+=	--disable-openct
.endif
