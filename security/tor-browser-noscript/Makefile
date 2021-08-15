# $NetBSD: Makefile,v 1.12 2021/08/15 13:20:11 wiz Exp $
#
# Changelog:
# https://noscript.net/changelog

VERSION=	11.2.11
DISTNAME=	noscript-${VERSION}
PKGNAME=	tor-browser-${DISTNAME}
CATEGORIES=	security www
MASTER_SITES=	https://secure.informaction.com/download/releases/
EXTRACT_SUFX=	.xpi

MAINTAINER=	wiz@NetBSD.org
HOMEPAGE=	https://noscript.net/
COMMENT=	Noscript plugin for tor-browser
LICENSE=	gnu-gpl-v3

INSTALLATION_DIRS+=	lib/tor-browser/distribution/extensions

do-build:

do-install:
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}${EXTRACT_SUFX} \
		${DESTDIR}${PREFIX}/lib/tor-browser/distribution/extensions/{73a6fe31-595d-460b-a920-fcc0f8843232}.xpi

.include "../../mk/bsd.pkg.mk"
