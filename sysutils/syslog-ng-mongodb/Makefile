# $NetBSD: Makefile,v 1.11 2022/04/18 19:12:08 adam Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module
PKGREVISION=		2

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-mongoc=system

.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
