# $NetBSD: Makefile,v 1.10 2023/09/17 10:56:56 leot Exp $

DISTNAME=	tlsx-1.1.4
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/tlsx
COMMENT=	TLS grabber focused on TLS based data collection
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/tlsx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
