# $NetBSD: Makefile,v 1.3 2005/06/16 06:57:52 jlam Exp $
#

DISTNAME=		xyame038
PKGNAME=		xyame-038
CATEGORIES=		emulators
MASTER_SITES=		http://www.emuxhaven.net/emuxhaven/multis/

MAINTAINER=		wiz@NetBSD.org
#HOMEPAGE=		http://www.geocities.co.jp/Stylish/2068/yame.html
COMMENT=		Multi-system emulator (Gameboy, NES, and PC-Engine)

DEPENDS+=		suse_x11>=6.1:../../emulators/${SUSE_DIR_PREFIX}_x11

WRKSRC=		${WRKDIR}
NO_CONFIGURE=	yes
NO_BUILD=	yes

CHECK_SHLIBS=	no

ONLY_FOR_PLATFORM+=	*-*-i386
INSTALLATION_DIRS=	bin man/man6

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xyame ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/yame.6 ${PREFIX}/man/man6/xyame.6

.include "../../emulators/suse_linux/Makefile.application"
.include "../../mk/bsd.pkg.mk"
