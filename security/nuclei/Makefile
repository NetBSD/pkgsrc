# $NetBSD: Makefile,v 1.37 2025/12/02 19:25:19 bsiegert Exp $

DISTNAME=	nuclei-3.4.10
PKGREVISION=	4
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
