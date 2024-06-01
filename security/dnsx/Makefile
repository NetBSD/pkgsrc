# $NetBSD: Makefile,v 1.17 2024/06/01 14:03:00 bsiegert Exp $

DISTNAME=	dnsx-1.2.1
PKGREVISION=	2
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
