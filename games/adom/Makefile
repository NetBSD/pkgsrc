# $NetBSD: Makefile,v 1.17 2012/10/06 11:54:30 asau Exp $

DISTNAME=	adom-111-elf
PKGNAME=	adom-1.1.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.adom.de/adom/download/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.adom.de/
COMMENT=	Ancient Domains of Mystery - yet another roguelike game

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}/adom
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin share/doc/adom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adom ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.* ${DESTDIR}${PREFIX}/share/doc/adom

.include "../../mk/bsd.pkg.mk"
