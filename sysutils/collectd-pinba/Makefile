# $NetBSD: Makefile,v 1.8 2024/01/30 18:29:20 adam Exp $

COLLECTD_PACKAGE=	pinba

COMMENT=		Statistics collection daemon - pinba plugin
PKGREVISION=		6

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}

TOOL_DEPENDS+=	protobuf>=3.0.0:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
