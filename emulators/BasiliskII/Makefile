# $NetBSD: Makefile,v 1.3 2002/08/01 05:48:11 jlam Exp $
#

DISTNAME=	BasiliskII_src_31052001
PKGNAME=	BasiliskII-0.9.1
CATEGORIES=	emulators
MASTER_SITES=	http://iphcip1.physik.uni-mainz.de/~cbauer/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.uni-mainz.de/~bauec002/B2Main.html
COMMENT=	Open Source 68k Macintosh emulator

WRKSRC=		${WRKDIR}/BasiliskII-0.9/src/Unix

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
PTHREAD_OPTS+=	require

.include "../../audio/esound/buildlink.mk"
.include "../../x11/gtk/buildlink.mk"
.include "../../mk/pthread.buildlink.mk"
.include "../../mk/x11.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
