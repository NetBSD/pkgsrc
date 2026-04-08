# $NetBSD: Makefile,v 1.41 2026/04/08 05:45:08 bsiegert Exp $

DISTNAME=	tlsx-1.2.2
PKGREVISION=	4
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
