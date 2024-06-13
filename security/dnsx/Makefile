# $NetBSD: Makefile,v 1.18 2024/06/13 13:47:07 bsiegert Exp $

DISTNAME=	dnsx-1.2.1
PKGREVISION=	3
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/dnsx
COMMENT=	DNS toolkit designed for running DNS queries
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/dnsx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
