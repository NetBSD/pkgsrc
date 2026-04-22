# $NetBSD: Makefile,v 1.32.2.1 2026/04/22 14:32:01 maya Exp $

DISTNAME=	vuln-1.1.4
PKGNAME=	${DISTNAME:S/vuln/govulncheck/}
PKGREVISION=	12
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
