# $NetBSD: Makefile,v 1.7 2020/10/31 00:54:38 wiz Exp $

VERSION=	11.1.3
DISTNAME=	noscript-${VERSION}
PKGNAME=	tor-browser-${DISTNAME}
CATEGORIES=	security www
MASTER_SITES=	https://secure.informaction.com/download/releases/
EXTRACT_SUFX=	.xpi

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://noscript.net/
COMMENT=	Noscript plugin for tor-browser
LICENSE=	gnu-gpl-v2

INSTALLATION_DIRS+=	lib/tor-browser/distribution/extensions

do-build:

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/lib/tor-browser/distribution/extensions/{73a6fe31-595d-460b-a920-fcc0f8843232}.xpi

.include "../../mk/bsd.pkg.mk"
