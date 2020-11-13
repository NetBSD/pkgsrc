# $NetBSD: Makefile,v 1.34 2020/11/13 19:26:18 bsiegert Exp $

DISTNAME=		go-grpc-1.15.0
PKGREVISION=		23
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=grpc/}
GITHUB_PROJECT=		grpc-go
GITHUB_TAG=		v${PKGVERSION_NOREV}

HOMEPAGE=		http://${GO_SRCPATH}
COMMENT=		Go language implementation of gRPC, HTTP/2 based RPC
LICENSE=		modified-bsd

GO_SRCPATH=		google.golang.org/grpc
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}

GO_BUILD_PATTERN=	${GO_SRCPATH}
.for godir in channelz codes connectivity credentials encoding \
	go_vet grpclog health internal interop keepalive metadata \
	naming peer reflection resolver stats status stress tap
GO_BUILD_PATTERN+=	${GO_SRCPATH}/${godir}/...
.endfor

CHECK_PORTABILITY_SKIP+=	benchmark/run_bench.sh
CHECK_PORTABILITY_SKIP+=	vet.sh

REPLACE_SH+=	balancer/grpclb/regenerate.sh
REPLACE_SH+=	benchmark/run_bench.sh
REPLACE_SH+=	channelz/service/regenerate.sh
REPLACE_SH+=	codegen.sh
REPLACE_SH+=	credentials/alts/internal/regenerate.sh
REPLACE_SH+=	health/regenerate.sh
REPLACE_SH+=	install_gae.sh
REPLACE_SH+=	vet.sh

.include "../../devel/go-glog/buildlink3.mk"
.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../misc/go-genproto-googleapis-rpc/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
