# $NetBSD: Makefile,v 1.1 2017/12/08 16:47:08 jperkin Exp $

COLLECTD_PACKAGE=	write_prometheus

COMMENT=		Statistics collection daemon - write_prometheus plugin

.include "../../sysutils/collectd/Makefile.common"

.include "../../devel/protobuf-c/buildlink3.mk"
.include "../../www/libmicrohttpd/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
