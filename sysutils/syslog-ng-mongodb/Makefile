# $NetBSD: Makefile,v 1.8 2021/04/21 11:42:44 adam Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module
PKGREVISION=		6

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-mongoc=system

.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
