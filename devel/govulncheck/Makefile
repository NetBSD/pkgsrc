# $NetBSD: Makefile,v 1.21 2025/01/19 18:33:33 wiz Exp $

DISTNAME=	vuln-1.1.4
PKGNAME=	${DISTNAME:S/vuln/govulncheck/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GITHUB:=golang/}
GITHUB_PROJECT=	vuln
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	bsiegert@NetBSD.org
HOMEPAGE=	https://vuln.go.dev/
COMMENT=	Go vulnerability checker tool
LICENSE=	modified-bsd

USE_LANGUAGES=	c

GO_BUILD_PATTERN=	./cmd/govulncheck

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
