# $NetBSD: Makefile,v 1.7 2003/05/02 11:54:48 wiz Exp $
#

DISTNAME=	BasiliskII_src_31052001
PKGNAME=	BasiliskII-0.9.1
PKGREVISION=	2
WRKSRC=		${WRKDIR}/BasiliskII-0.9/src/Unix
CATEGORIES=	emulators
MASTER_SITES=	http://iphcip1.physik.uni-mainz.de/~cbauer/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uni-mainz.de/~bauec002/B2Main.html
COMMENT=	Open Source 68k Macintosh emulator

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes
PTHREAD_OPTS+=	require

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/BasiliskII
	${INSTALL_DATA} ${WRKSRC}/../../README ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/../../TECH ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/../../TODO ${PREFIX}/share/doc/BasiliskII/

.include "../../audio/esound/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
