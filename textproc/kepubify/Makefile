# $NetBSD: Makefile,v 1.15.2.1 2026/07/14 00:36:08 maya Exp $

DISTNAME=	kepubify-4.0.4
PKGREVISION=	15
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_GITHUB:=pgaskin/}
GITHUB_TAG=	v${PKGVERSION_NOREV}

MAINTAINER=	leot@NetBSD.org
HOMEPAGE=	https://pgaskin.net/kepubify
COMMENT=	Fast, standalone EPUB to Kobo EPUB conversion tool
LICENSE=	mit

post-install:
	${RM} ${DESTDIR}${PREFIX}/bin/kobotest

.include "go-modules.mk"

.include "../../lang/go/go-module.mk"
.include "../../mk/bsd.pkg.mk"
