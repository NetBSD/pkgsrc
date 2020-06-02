# $NetBSD: Makefile,v 1.6 2020/06/02 08:24:48 adam Exp $

SYSLOG_MOD=		mongodb
SYSLOG_MOD_DIR=		afmongodb
COMMENT=		Syslog-ng MongoDB module
PKGREVISION=		4

.include "../../sysutils/syslog-ng/Makefile.module"

CONFIGURE_ARGS+=	--with-mongoc=system

.include "../../databases/mongo-c-driver/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
