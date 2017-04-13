# $NetBSD: Makefile,v 1.5 2017/04/13 15:12:05 bsiegert Exp $

DISTNAME=		go-grpc-1.0.1
PKGREVISION=		4
CATEGORIES=		net
MASTER_SITES=		${MASTER_SITE_GITHUB:=grpc/}
GITHUB_PROJECT=		grpc-go
GITHUB_TAG=		v1.0.1-GA

HOMEPAGE=		http://${GO_SRCPATH}
COMMENT=		Go language implementation of gRPC, HTTP/2 based RPC
LICENSE=		modified-bsd

GO_SRCPATH=		google.golang.org/grpc
GO_DIST_BASE=		${GITHUB_PROJECT}-${GITHUB_TAG:S/v//}
GO_BUILD_PATTERN=	${GO_SRCPATH}
GO_BUILD_PATTERN+=	${GO_SRCPATH}/codes/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/credentials/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/grpclog/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/health/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/metadata/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/naming/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/peer/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/reflection/...
GO_BUILD_PATTERN+=	${GO_SRCPATH}/transport/...

REPLACE_SH+=		codegen.sh
REPLACE_SH+=		coverage.sh

#pre-patch:
#	${RM} -rf ${WRKSRC}/test

# due to patch
post-install:
	${RM} -f ${DESTDIR}${PREFIX}/gopkg/src/google.golang.org/grpc/coverage.sh.orig

.include "../../devel/go-glog/buildlink3.mk"
.include "../../devel/go-protobuf/buildlink3.mk"
.include "../../net/go-net/buildlink3.mk"
.include "../../security/go-oauth2/buildlink3.mk"
.include "../../lang/go/go-package.mk"
.include "../../mk/bsd.pkg.mk"
