# $NetBSD: Makefile,v 1.15 2024/01/10 19:14:37 bsiegert Exp $

DISTNAME=	httpx-1.3.5
PKGREVISION=	5
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
