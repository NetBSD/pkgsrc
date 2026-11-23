# $NetBSD: Makefile,v 1.5 2026/11/23 18:56:58 drixter Exp $

DISTNAME=	vulnx-2.1.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/projectdiscovery/vulnx
COMMENT=	Modern CLI for exploring vulnerability data
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/vulnx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
