# $NetBSD: Makefile,v 1.3 2021/03/07 14:19:42 wiz Exp $

COLLECTD_PACKAGE=	mongodb
COLLECTD_PLUGINS=	write_mongodb

COMMENT=		Statistics collection daemon - write_mongodb plugin

.include "../../databases/mongo-c-driver/buildlink3.mk"
COLLECTD_LIB.mongoc=	yes # help says argument is the path, but everything but "yes" disables

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
