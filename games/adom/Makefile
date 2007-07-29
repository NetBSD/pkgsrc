# $NetBSD: Makefile,v 1.14 2007/07/29 05:19:25 jlam Exp $

DISTNAME=	adom-111-elf
PKGNAME=	adom-1.1.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.adom.de/adom/download/linux/

MAINTAINER=	shattered@users.sourceforge.net
HOMEPAGE=	http://www.adom.de/
COMMENT=	Ancient Domains of Mystery - yet another roguelike game

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}/adom
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin share/doc/adom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adom ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.* ${PREFIX}/share/doc/adom

.include "../../mk/bsd.pkg.mk"
