# $NetBSD: Makefile,v 1.5 2023/10/15 12:04:24 bsiegert Exp $

DISTNAME=	croc-9.6.5
PKGREVISION=	4
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_GITHUB:=schollz/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	charlotte@NetBSD.org
HOMEPAGE=	https://schollz.com/tinker/croc6/
COMMENT=	Fast, simple, and secure file transfer between any two computers
LICENSE=	mit

.include "go-modules.mk"

post-install:
	${RM} -f ${DESTDIR}${PREFIX}/bin/install

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
