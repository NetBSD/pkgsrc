# $NetBSD: Makefile,v 1.18.2.1 2025/04/05 20:45:03 maya Exp $

DISTNAME=	croc-9.6.14
PKGREVISION=	8
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
