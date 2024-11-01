# $NetBSD: Makefile,v 1.19 2024/11/01 12:54:32 wiz Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module
PKGREVISION=		6

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-mongoc=system

.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
