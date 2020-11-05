# $NetBSD: Makefile,v 1.7 2020/11/05 09:09:11 ryoon Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module
PKGREVISION=		5

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-mongoc=system

.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
