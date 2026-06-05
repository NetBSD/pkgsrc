# $NetBSD: Makefile,v 1.2 2026/06/05 10:21:49 bsiegert Exp $

DISTNAME=	zauth-0.0.0pre20230628
PKGREVISION=	1
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_GITHUB:=RijulGulati/}
GITHUB_TAG=	aa4767a896c1f73ae58b0044ad78f2681d017680
GITHUB_PROJECT=	zauth

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	${MASTER_SITE_GITHUB:=RijulGulati/zauth/}
COMMENT=	2FA application for CLI terminal
LICENSE=	mit

do-install:
	${INSTALL_PROGRAM} ${WRKDIR}/.gopath/bin/zauth ${DESTDIR}${PREFIX}/bin

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
