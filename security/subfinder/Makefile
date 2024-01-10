# $NetBSD: Makefile,v 1.14 2024/01/10 19:14:38 bsiegert Exp $

DISTNAME=	subfinder-2.6.3
PKGREVISION=	5
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
