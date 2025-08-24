# $NetBSD: Makefile,v 1.15 2025/08/24 16:36:19 wiz Exp $

COLLECTD_PACKAGE=	pinba

COMMENT=		Statistics collection daemon - pinba plugin
PKGREVISION=		13

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}

TOOL_DEPENDS+=	protobuf>=3.0.0:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
