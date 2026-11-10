# $NetBSD: Makefile,v 1.4 2026/11/10 18:55:16 bsiegert Exp $

DISTNAME=	raven-0.3.3
PKGREVISION=	3
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=nokia/}
GITHUB_PROJECT=	bgp-routing-security-monitor
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/nokia/bgp-routing-security-monitor
COMMENT=	Routing Analysis, Validation, and Event Network
LICENSE=	modified-bsd

GO_BUILD_PATTERN=	./cmd/raven

USE_LANGUAGES=		c

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
