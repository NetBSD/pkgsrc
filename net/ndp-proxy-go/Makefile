# $NetBSD: Makefile,v 1.2 2026/11/10 18:55:15 bsiegert Exp $

DISTNAME=	ndp-proxy-go-1.1.1
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=Monviech/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/Monviech/ndp-proxy-go/
COMMENT=	IPv6 Neighbor Discovery Protocol (NDP) Proxy
LICENSE=	2-clause-bsd

USE_LANGUAGES=	c

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
