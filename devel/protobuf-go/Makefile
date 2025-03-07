# $NetBSD: Makefile,v 1.4 2025/03/07 20:54:18 bsiegert Exp $

DISTNAME=	protobuf-go-1.34.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	3
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
