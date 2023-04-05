# $NetBSD: Makefile,v 1.3 2023/04/05 20:47:51 bsiegert Exp $

DISTNAME=	nuclei-2.9.1
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
