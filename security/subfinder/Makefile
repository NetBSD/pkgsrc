# $NetBSD: Makefile,v 1.41 2026/05/07 18:50:05 bsiegert Exp $

DISTNAME=	subfinder-2.12.0
PKGREVISION=	4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/subfinder
COMMENT=	Fast passive subdomain enumeration tool
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/subfinder

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
