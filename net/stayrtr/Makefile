# $NetBSD: Makefile,v 1.3 2026/10/20 20:28:11 bsiegert Exp $

DISTNAME=	stayrtr-0.6.4
PKGREVISION=	2
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
