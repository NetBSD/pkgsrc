# $NetBSD: Makefile,v 1.3 2018/04/17 22:29:51 wiz Exp $

COLLECTD_PACKAGE=	write_prometheus

COMMENT=		Statistics collection daemon - write_prometheus plugin
PKGREVISION=		2

.include "../../sysutils/collectd/Makefile.common"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
