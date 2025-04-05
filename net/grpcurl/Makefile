# $NetBSD: Makefile,v 1.3.2.1 2025/04/05 20:45:04 maya Exp $

DISTNAME=	grpcurl-1.9.1
GITHUB_TAG=	v${PKGVERSION_NOREV}
PKGREVISION=	3
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
