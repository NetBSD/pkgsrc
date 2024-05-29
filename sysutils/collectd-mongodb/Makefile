# $NetBSD: Makefile,v 1.11 2024/05/29 16:34:23 adam Exp $

COLLECTD_PACKAGE=	mongodb
COLLECTD_PLUGINS=	write_mongodb

COMMENT=		Statistics collection daemon - write_mongodb plugin
PKGREVISION=		8

.include "../../databases/mongo-c-driver/buildlink3.mk"
COLLECTD_LIB.mongoc=	yes # help says argument is the path, but everything but "yes" disables

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
