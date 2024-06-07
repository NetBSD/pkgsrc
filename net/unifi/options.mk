# $NetBSD: options.mk,v 1.4 2024/06/07 15:33:17 abs Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.unifi
PKG_OPTIONS_GROUP.mongodb=	mongodb4 mongodb6
PKG_OPTIONS_REQUIRED_GROUPS=	mongodb
PKG_SUGGESTED_OPTIONS=		mongodb4

.include "../../mk/bsd.options.mk"

# Note a backup/restore is required when switching versions
.if !empty(PKG_OPTIONS:Mmongodb4)
DEPENDS+=		mongodb>=4.0<6:../../databases/mongodb4
.endif

# Note a backup/restore is required when switching versions
.if !empty(PKG_OPTIONS:Mmongodb6)
DEPENDS+=		mongodb>=6.0:../../databases/mongodb
.endif
