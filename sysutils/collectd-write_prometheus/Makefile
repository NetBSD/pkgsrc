# $NetBSD: Makefile,v 1.11 2021/01/14 16:13:40 wiz Exp $

COLLECTD_PACKAGE=	write_prometheus
PKGREVISION=		1

COMMENT=		Statistics collection daemon - write_prometheus plugin

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}
.include "../../www/libmicrohttpd/buildlink3.mk"
COLLECTD_LIB.microhttpd=${BUILDLINK_PREFIX.libmicrohttpd}

BUILD_DEPENDS+=	protobuf-[0-9]*:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
