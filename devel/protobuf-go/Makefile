# $NetBSD: Makefile,v 1.16 2026/05/07 18:49:55 bsiegert Exp $

DISTNAME=	protobuf-go-1.34.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	15
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=protocolbuffers/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/protocolbuffers/protobuf-go/
COMMENT=	Protocol Buffers implementation in Go
LICENSE=	modified-bsd

.include "go-modules.mk"

DEPENDS+=	protobuf-[0-9]*:../../devel/protobuf

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
