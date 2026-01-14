# $NetBSD: Makefile,v 1.26 2026/01/14 12:57:36 wiz Exp $

COLLECTD_PACKAGE=	grpc

COMMENT=	Statistics collection daemon - grpc plugin
PKGREVISION=	21

BROKEN+=	"fatal error: absl/synchronization/mutex.h: No such file or directory"

.include "../../net/grpc/buildlink3.mk"
.include "../../devel/protobuf/buildlink3.mk"
.include "../../devel/protobuf-c/buildlink3.mk"
COLLECTD_LIB.grpcpp=	${BUILDLINK_PREFIX.grpc}
COLLECTD_LIB.protobuf=	${BUILDLINK_PREFIX.protobuf}
COLLECTD_LIB.protobuf-c=${BUILDLINK_PREFIX.protobuf-c}

TOOL_DEPENDS+=	protobuf>=3.0.0:../../devel/protobuf

.include "../../sysutils/collectd/Makefile.common"

.include "../../mk/bsd.pkg.mk"
