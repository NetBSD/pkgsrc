# $NetBSD: Makefile,v 1.4 2002/09/06 12:30:10 wiz Exp $
#

DISTNAME=	BasiliskII_src_31052001
PKGNAME=	BasiliskII-0.9.1
CATEGORIES=	emulators
MASTER_SITES=	http://iphcip1.physik.uni-mainz.de/~cbauer/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uni-mainz.de/~bauec002/B2Main.html
COMMENT=	Open Source 68k Macintosh emulator

WRKSRC=		${WRKDIR}/BasiliskII-0.9/src/Unix

USE_BUILDLINK2=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_X11=	yes
PTHREAD_OPTS+=	require

.include "../../audio/esound/buildlink2.mk"
.include "../../x11/gtk/buildlink2.mk"
.include "../../mk/pthread.buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
