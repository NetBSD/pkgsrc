# $NetBSD: options.mk,v 1.2 2010/05/14 20:12:58 asau Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.openmpi
PKG_SUPPORTED_OPTIONS=	debug openmpi-vampirtrace
PKG_SUGGESTED_OPTIONS=	openmpi-vampirtrace

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mdebug)
CONFIGURE_ARGS+=	--enable-debug
.endif

# Allow coexistance of OpenMPI and libotf by disabling OpenMPI parts:
.if !empty(PKG_OPTIONS:Mopenmpi-vampirtrace)
CONFLICTS+=	libotf-[0-9]*
PLIST_SRC+=	PLIST.vt
.include "../../graphics/freetype2/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--enable-contrib-no-build=vt
.endif

PLIST_SRC+=	PLIST
