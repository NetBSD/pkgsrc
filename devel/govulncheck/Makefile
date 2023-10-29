# $NetBSD: Makefile,v 1.7 2023/10/29 14:48:12 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	vuln
DISTNAME=	vuln-1.0.1
PKGNAME=	govulncheck-1.0.1
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://vuln.go.dev/
COMMENT=	Go vulnerability checker tool
LICENSE=	modified-bsd

USE_LANGUAGES=	c

GO_BUILD_PATTERN=	./cmd/govulncheck

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
