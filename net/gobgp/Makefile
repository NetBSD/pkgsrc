# $NetBSD: Makefile,v 1.3 2026/10/13 18:37:48 bsiegert Exp $

DISTNAME=	gobgp-4.10.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=osrg/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/osrg/gobgp/
COMMENT=	GoBGP: BGP implementation in Go
LICENSE=	apache-2.0

USE_LANGUAGES=	c

# 'config' is a too common filename, rename it to 'gobgp-config'
post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/config \
		${DESTDIR}${PREFIX}/bin/gobgp-config

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
