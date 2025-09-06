# $NetBSD: Makefile,v 1.7 2025/09/06 13:17:03 bsiegert Exp $

DISTNAME=	grpcurl-1.9.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	6
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=fullstorydev/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/fullstorydev/grpcurl/
COMMENT=	Command-line tool that lets you interact with gRPC servers
LICENSE=	mit

USE_LANGUAGES=	c

GO_BUILD_PATTERN=	./cmd/grpcurl

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
