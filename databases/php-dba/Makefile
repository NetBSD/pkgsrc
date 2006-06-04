# $NetBSD: Makefile,v 1.8 2006/06/04 16:26:53 joerg Exp $

MODNAME=		dba
CATEGORIES+=		databases
COMMENT=		PHP extension for DBM database access

CONFLICTS=	php-dba-[0-9]*

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
