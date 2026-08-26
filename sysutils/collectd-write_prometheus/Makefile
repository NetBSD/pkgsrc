# $NetBSD: Makefile,v 1.43 2026/08/26 10:19:10 adam Exp $

COLLECTD_PACKAGE=	write_prometheus

COMMENT=		Statistics collection daemon - write_prometheus plugin
PKGREVISION=		30

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}
.include "../../www/libmicrohttpd/buildlink3.mk"
COLLECTD_LIB.microhttpd=${BUILDLINK_PREFIX.libmicrohttpd}

TOOL_DEPENDS+=	protobuf-[0-9]*:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
