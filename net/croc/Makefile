# $NetBSD: Makefile,v 1.34 2026/08/15 12:53:26 bsiegert Exp $

DISTNAME=	croc-11.1.0
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=schollz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@NetBSD.org
HOMEPAGE=	https://schollz.com/tinker/croc6/
COMMENT=	Fast, simple, and secure file transfer between any two computers
LICENSE=	mit

USE_LANGUAGES=	c

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/install

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
