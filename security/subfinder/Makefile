# $NetBSD: Makefile,v 1.16 2024/03/24 20:17:06 leot Exp $

DISTNAME=	subfinder-2.6.5
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/subfinder
COMMENT=	Fast passive subdomain enumeration tool
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/subfinder

WRKSRC=		${WRKDIR}/${DISTNAME}/v2

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
