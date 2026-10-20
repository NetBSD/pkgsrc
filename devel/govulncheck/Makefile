# $NetBSD: Makefile,v 1.42 2026/10/20 20:28:02 bsiegert Exp $

DISTNAME=	vuln-1.1.4
PKGNAME=	${DISTNAME:S/vuln/govulncheck/}
PKGREVISION=	21
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
