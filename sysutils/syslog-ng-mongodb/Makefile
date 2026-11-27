# $NetBSD: Makefile,v 1.24 2026/11/27 11:01:43 adam Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module

.include "../../sysutils/syslog-ng/module.mk"

CONFIGURE_ARGS+=	--with-mongoc=system

.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
