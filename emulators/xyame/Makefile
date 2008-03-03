# $NetBSD: Makefile,v 1.10 2008/03/03 19:21:39 jlam Exp $
#

DISTNAME=		xyame038
PKGNAME=		xyame-038
PKGREVISION=		1
CATEGORIES=		emulators
MASTER_SITES=		http://www.emuxhaven.net/emuxhaven/multis/

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=		http://www.geocities.co.jp/Stylish/2068/yame.html
COMMENT=		Multi-system emulator (Gameboy, NES, and PC-Engine)

EMUL_PLATFORMS=		linux-i386
EMUL_MODULES.linux=	x11

PKG_DESTDIR_SUPPORT=	user-destdir

WRKSRC=			${WRKDIR}
BUILD_DIRS=		# empty

INSTALLATION_DIRS=	bin ${PKGMANDIR}/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xyame ${DESTDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yame.6 \
		${DESTDIR}${PREFIX}/${PKGMANDIR}/man6/xyame.6

.include "../../mk/bsd.pkg.mk"
