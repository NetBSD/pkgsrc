# $NetBSD: Makefile,v 1.2 2020/12/06 10:50:51 wiz Exp $

PKGREVISION=		1
COLLECTD_PACKAGE=	grpc

COMMENT=		Statistics collection daemon - grpc plugin

.include "../../net/grpc/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.grpcpp=	${BUILDLINK_PREFIX.grpc}
COLLECTD_LIB.protobuf=	${BUILDLINK_PREFIX.protobuf}
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}

BUILD_DEPENDS+=	protobuf>=3.0.0:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
