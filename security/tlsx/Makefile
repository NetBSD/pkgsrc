# $NetBSD: Makefile,v 1.21 2024/06/13 13:47:08 bsiegert Exp $

DISTNAME=	tlsx-1.1.6
PKGREVISION=	3
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
