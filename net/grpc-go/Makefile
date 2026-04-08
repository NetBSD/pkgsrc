# $NetBSD: Makefile,v 1.14 2026/04/08 05:45:01 bsiegert Exp $

DISTNAME=	grpc-go-1.66.0
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	13
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
