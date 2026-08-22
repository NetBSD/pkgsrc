# $NetBSD: Makefile,v 1.40 2026/08/22 15:19:05 bsiegert Exp $

DISTNAME=	croc-11.2.2
PKGREVISION=	1
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=schollz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://schollz.com/tinker/croc6/
COMMENT=	Fast, simple, and secure file transfer between any two computers
LICENSE=	mit

USE_LANGUAGES=	c

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/install

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
