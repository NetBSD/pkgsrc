# $NetBSD: Makefile,v 1.8 2004/04/25 01:12:49 xtraeme Exp $

MODNAME=		dba
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for DBM database access

USE_BUILDLINK3=		YES

.include "../../www/php4/Makefile.module"

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

.include "../../mk/bsd.pkg.mk"
