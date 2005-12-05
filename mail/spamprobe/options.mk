# $NetBSD: options.mk,v 1.2 2005/12/05 23:55:11 rillig Exp $

PKG_OPTIONS_VAR=		PKG_OPTIONS.spamprobe
PKG_SUPPORTED_OPTIONS=		bdb
PKG_SUGGESTED_OPTIONS=		bdb

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=           db4 # db3 db2 (not tested)
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=        --with-db=${BDBBASE:Q}
.endif

