# $NetBSD: Makefile,v 1.20 2019/06/24 10:36:50 nia Exp $

DISTNAME=	adom-111-elf
PKGNAME=	adom-1.1.1
PKGREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.adom.de/adom/download/linux/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.adom.de/home/index.html
COMMENT=	Ancient Domains of Mystery - yet another roguelike game
LICENSE=	adom-license

RESTRICTED=		Explicit restrictions on distribution
NO_BIN_ON_CDROM=	${RESTRICTED}
NO_BIN_ON_FTP=		${RESTRICTED}
NO_SRC_ON_CDROM=	${RESTRICTED}
NO_SRC_ON_FTP=		${RESTRICTED}

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	base

WRKSRC=			${WRKDIR}/adom
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin share/doc/adom

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/adom ${DESTDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/*.* ${DESTDIR}${PREFIX}/share/doc/adom

.include "../../mk/bsd.pkg.mk"
