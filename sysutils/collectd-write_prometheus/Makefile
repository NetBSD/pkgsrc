# $NetBSD: Makefile,v 1.18 2022/04/03 18:50:21 adam Exp $

COLLECTD_PACKAGE=	write_prometheus

COMMENT=		Statistics collection daemon - write_prometheus plugin
PKGREVISION=		6

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}
.include "../../www/libmicrohttpd/buildlink3.mk"
COLLECTD_LIB.microhttpd=${BUILDLINK_PREFIX.libmicrohttpd}

BUILD_DEPENDS+=	protobuf-[0-9]*:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
