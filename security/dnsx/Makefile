# $NetBSD: Makefile,v 1.43 2026/10/10 17:32:00 leot Exp $

DISTNAME=	dnsx-1.3.1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/dnsx
COMMENT=	DNS toolkit designed for running DNS queries
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/dnsx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
