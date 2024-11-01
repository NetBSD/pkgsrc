# $NetBSD: Makefile,v 1.13 2024/11/01 12:54:23 wiz Exp $

COLLECTD_PACKAGE=	mongodb
COLLECTD_PLUGINS=	write_mongodb

COMMENT=		Statistics collection daemon - write_mongodb plugin
PKGREVISION=		10

.include "../../databases/mongo-c-driver/buildlink3.mk"
COLLECTD_LIB.mongoc=	yes # help says argument is the path, but everything but "yes" disables

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
