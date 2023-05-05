# $NetBSD: Makefile,v 1.5 2023/05/05 19:37:36 bsiegert Exp $

DISTNAME=	nuclei-2.9.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://nuclei.projectdiscovery.io/
COMMENT=	Fast and customizable vulnerability scanner
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/nuclei

WRKSRC=		${WRKDIR}/${DISTNAME}/v2

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
