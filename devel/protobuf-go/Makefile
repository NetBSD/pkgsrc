# $NetBSD: Makefile,v 1.1 2024/07/05 20:25:24 maya Exp $

DISTNAME=	protobuf-go-1.34.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
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
