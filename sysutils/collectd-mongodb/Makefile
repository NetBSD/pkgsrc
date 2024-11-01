# $NetBSD: Makefile,v 1.12 2024/11/01 00:53:36 wiz Exp $

COLLECTD_PACKAGE=	mongodb
COLLECTD_PLUGINS=	write_mongodb

COMMENT=		Statistics collection daemon - write_mongodb plugin
PKGREVISION=		9

.include "../../databases/mongo-c-driver/buildlink3.mk"
COLLECTD_LIB.mongoc=	yes # help says argument is the path, but everything but "yes" disables

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
