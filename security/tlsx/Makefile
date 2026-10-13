# $NetBSD: Makefile,v 1.50 2026/10/13 18:37:56 bsiegert Exp $

DISTNAME=	tlsx-1.4.0
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=projectdiscovery/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/projectdiscovery/tlsx
COMMENT=	TLS grabber focused on TLS based data collection
LICENSE=	mit

GO_BUILD_PATTERN+=	./cmd/tlsx

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
