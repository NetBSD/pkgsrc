# $NetBSD: Makefile,v 1.5 2005/12/05 20:49:58 rillig Exp $

MODNAME=		dba
CATEGORIES+=		databases
COMMENT=		PHP extension for DBM database access


CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

CONFIGURE_ARGS+=	--without-cdb
CONFIGURE_ARGS+=	--without-db2
CONFIGURE_ARGS+=	--without-db3
CONFIGURE_ARGS+=	--without-dbm

.if exists(/usr/include/ndbm.h)
CONFIGURE_ARGS+=	--without-gdbm
CONFIGURE_ARGS+=	--with-ndbm=/usr
.else
CONFIGURE_ARGS+=	--with-gdbm=shared,${BUILDLINK_PREFIX.gdbm}
CONFIGURE_ARGS+=	--without-ndbm
.include "../../databases/gdbm/buildlink3.mk"
.endif

.include "../../lang/php/ext.mk"
.include "../../mk/bsd.pkg.mk"
