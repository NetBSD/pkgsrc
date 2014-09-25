# $NetBSD: options.mk,v 1.11 2014/09/25 14:24:07 jperkin Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.spamprobe
PKG_SUPPORTED_OPTIONS=		bdb gif png jpeg
PKG_SUGGESTED_OPTIONS=		bdb gif png jpeg

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db4 db5 # db3 db2 (not tested)
BUILDLINK_TRANSFORM+=	l:db:${BDB_TYPE}
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-db=${BDBBASE}
.endif

.if !empty(PKG_OPTIONS:Mgif)
.include "../../graphics/giflib/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mpng)
.include "../../graphics/png/buildlink3.mk"
.endif

.if !empty(PKG_OPTIONS:Mjpeg)
.include "../../mk/jpeg.buildlink3.mk"
.endif
