# $NetBSD: Makefile,v 1.7 2005/06/16 06:57:52 jlam Exp $
#

DISTNAME=	adom-111-elf
PKGNAME=	adom-1.1.1
CATEGORIES=	games
MASTER_SITES=	http://www.adom.de/adom/download/linux/

MAINTAINER=	svs@ropnet.ru
HOMEPAGE=	http://www.adom.de/
COMMENT=	Ancient Domains of Mystery - yet another roguelike game

ONLY_FOR_PLATFORM=	NetBSD-*-i386 Linux-*-i386

WRKSRC=		${WRKDIR}/adom
NO_BUILD=	YES
NO_CONFIGURE=	YES
CHECK_SHLIBS=	NO

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} == "NetBSD"
DEPENDS=	suse_base>=6.1:../../emulators/${SUSE_DIR_PREFIX}_base
.endif

INSTALLATION_DIRS=	bin

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/adom
	${INSTALL_DATA} ${WRKSRC}/*.* ${PREFIX}/share/doc/adom
	${INSTALL_PROGRAM} ${WRKSRC}/adom ${PREFIX}/bin

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
