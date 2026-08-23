# $NetBSD: Makefile,v 1.41 2026/08/23 10:58:46 drixter Exp $

DISTNAME=	croc-11.2.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=schollz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	drixter@e-utp.net
HOMEPAGE=	https://schollz.com/tinker/croc6/
COMMENT=	Fast, simple, and secure file transfer between any two computers
LICENSE=	mit

USE_LANGUAGES=	c

GO_VERSION_REQD=	127

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/install

.include "go-modules.mk"
.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
