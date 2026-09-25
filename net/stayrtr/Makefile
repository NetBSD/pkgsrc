# $NetBSD: Makefile,v 1.1 2026/09/25 13:09:18 drixter Exp $

DISTNAME=	stayrtr-0.6.4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgp/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/bgp/stayrtr/
COMMENT=	RPKI-To-Router server implementation in Go
LICENSE=	modified-bsd

USE_LANGUAGES=	c

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
