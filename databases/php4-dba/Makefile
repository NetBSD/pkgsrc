# $NetBSD: Makefile,v 1.2 2001/10/16 07:12:35 jlam Exp $

.include "../../www/php4/Makefile.module"

MODNAME=		dba
CATEGORIES+=		databases
PHP_PKG_VERS=		# empty
COMMENT=		PHP4 extension for DBM database access

USE_BUILDLINK_ONLY=	YES
CONFIGURE_ARGS+=	--enable-${MODNAME}=shared

CONFIGURE_ARGS+=	--without-cdb
CONFIGURE_ARGS+=	--without-db2
CONFIGURE_ARGS+=	--without-db3
CONFIGURE_ARGS+=	--without-dbm

.if exists(/usr/include/ndbm.h)
CONFIGURE_ARGS+=	--without-gdbm
CONFIGURE_ARGS+=	--with-ndbm=/usr
.else
CONFIGURE_ARGS+=	--with-gdbm=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--without-ndbm
.include "../../databases/gdbm/buildlink.mk"
.endif

.include "../../mk/bsd.pkg.mk"
