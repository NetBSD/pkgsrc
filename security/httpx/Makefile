# $NetBSD: Makefile,v 1.2 2023/03/17 10:28:00 leot Exp $

DISTNAME=	httpx-1.2.9
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
