# $NetBSD: Makefile,v 1.34 2025/12/12 11:10:58 leot Exp $

DISTNAME=	subfinder-2.10.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/subfinder
COMMENT=	Fast passive subdomain enumeration tool
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/subfinder

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
