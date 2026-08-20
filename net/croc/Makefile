# $NetBSD: Makefile,v 1.38 2026/08/20 21:58:08 drixter Exp $

DISTNAME=	croc-11.2.2
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
