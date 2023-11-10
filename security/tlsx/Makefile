# $NetBSD: Makefile,v 1.14 2023/11/10 15:45:20 bsiegert Exp $

DISTNAME=	tlsx-1.1.5
PKGREVISION=	2
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
