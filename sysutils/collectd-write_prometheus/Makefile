# $NetBSD: Makefile,v 1.8 2020/05/22 10:56:39 adam Exp $

COLLECTD_PACKAGE=	write_prometheus

COMMENT=		Statistics collection daemon - write_prometheus plugin
PKGREVISION=		7

.include "../../sysutils/collectd/Makefile.common"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
