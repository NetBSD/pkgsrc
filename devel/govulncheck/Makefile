# $NetBSD: Makefile,v 1.3 2023/08/26 16:31:28 bsiegert Exp $

GITHUB_TAG=	v${PKGVERSION_NOREV}
GITHUB_PROJECT=	vuln
DISTNAME=	vuln-1.0.0
PKGNAME=	govulncheck-1.0.0
PKGREVISION=	1
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
