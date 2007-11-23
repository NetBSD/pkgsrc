# $NetBSD: options.mk,v 1.1 2007/11/23 12:34:29 obache Exp $

PKG_OPTIONS_VAR=	PKG_OPTIONS.php-dba
PKG_SUPPORTED_OPTIONS=	bdb gdbm
.if !exists(/usr/include/ndbm.h)
PKG_SUGGESTED_OPTIONS+=	gdbm
.endif

.include "../../mk/bsd.options.mk"

.if !empty(PKG_OPTIONS:Mgdbm)
.include "../../databases/gdbm/buildlink3.mk"
CONFIGURE_ARGS+=	--with-gdbm=${BUILDLINK_PREFIX.gdbm}
.else
CONFIGURE_ARGS+=	--without-gdbm
.endif

.if !empty(PKG_OPTIONS:Mbdb)
BDB_ACCEPTED=		db2 db3 db4
.include "../../mk/bdb.buildlink3.mk"
CONFIGURE_ARGS+=	--with-${BDB_TYPE}=${BDBBASE}
.  for bdb in ${BDB_ACCEPTED}
.    if ${bdb}!=${BDB_TYPE}
CONFIGURE_ARGS+=	--without-${bdb}
.    endif
.  endfor
.else
.  for dbd in ${BDB_ACCEPTED}
CONFIGURE_ARGS+=	--without-${bdb}
.  endfor
.endif
