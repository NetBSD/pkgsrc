# $NetBSD: Makefile,v 1.9 2024/04/05 14:01:01 wiz Exp $

COLLECTD_PACKAGE=	pinba

COMMENT=		Statistics collection daemon - pinba plugin
PKGREVISION=		7

.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}

TOOL_DEPENDS+=	protobuf>=3.0.0:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
