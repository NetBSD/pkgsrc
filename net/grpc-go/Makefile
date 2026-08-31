# $NetBSD: Makefile,v 1.20 2026/08/31 19:18:56 bsiegert Exp $

DISTNAME=	grpc-go-1.66.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	19
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=grpc/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/grpc/grpc-go/
COMMENT=	Go implementation of gRPC
LICENSE=	apache-2.0

WRKSRC=		${WRKDIR}/${DISTNAME}/cmd/protoc-gen-go-grpc

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
