# $NetBSD: Makefile,v 1.2 2026/08/15 12:53:26 bsiegert Exp $

DISTNAME=	bgpipe-0.22.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=bgpfix/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://github.com/bgpfix/bgpipe/
COMMENT=	Open-source tool that processes BGP messages through a pipeline
LICENSE=	mit

USE_LANGUAGES=	c

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/bgpipe ${DESTDIR}${PREFIX}/bin/bgpipe

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
