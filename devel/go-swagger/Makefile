# $NetBSD: Makefile,v 1.37 2026/08/22 15:18:59 bsiegert Exp $

DISTNAME=	go-swagger-0.30.4
MASTER_SITES=	${MASTER_SITE_GITHUB:=go-swagger/}
PKGREVISION=	36
CATEGORIES=	devel
GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	go-swagger

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://goswagger.io/
COMMENT=	Swagger 2.0 implementation for Go
LICENSE=	apache-2.0

GO_BUILD_PATTERN=	./cmd/swagger

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
