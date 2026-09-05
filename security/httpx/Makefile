# $NetBSD: Makefile,v 1.47 2026/09/05 19:09:58 bsiegert Exp $

DISTNAME=	httpx-1.8.1
PKGREVISION=	10
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/httpx
COMMENT=	HTTP toolkit that allows running multiple probes
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/httpx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
