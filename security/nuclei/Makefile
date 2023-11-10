# $NetBSD: Makefile,v 1.16 2023/11/10 15:45:19 bsiegert Exp $

DISTNAME=	nuclei-3.0.2
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://nuclei.projectdiscovery.io/
COMMENT=	Fast and customizable vulnerability scanner
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/nuclei

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
