# $NetBSD: Makefile,v 1.14 2021/09/29 19:01:20 adam Exp $

COLLECTD_PACKAGE=	write_prometheus

COMMENT=		Statistics collection daemon - write_prometheus plugin
PKGREVISION=		2

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}
.include "../../www/libmicrohttpd/buildlink3.mk"
COLLECTD_LIB.microhttpd=${BUILDLINK_PREFIX.libmicrohttpd}

BUILD_DEPENDS+=	protobuf-[0-9]*:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
