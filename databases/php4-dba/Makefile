# $NetBSD: Makefile,v 1.4 2002/02/28 06:16:48 jlam Exp $

MODNAME=		dba
CATEGORIES+=		databases
PKGREVISION=		# empty
COMMENT=		PHP4 extension for DBM database access

USE_BUILDLINK_ONLY=	YES

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
CONFIGURE_ARGS+=	--with-gdbm=shared,${BUILDLINK_DIR}
CONFIGURE_ARGS+=	--without-ndbm
.include "../../databases/gdbm/buildlink.mk"
.endif

.include "../../mk/bsd.pkg.mk"
