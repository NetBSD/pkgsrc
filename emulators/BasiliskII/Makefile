# $NetBSD: Makefile,v 1.1.1.1 2001/12/29 00:22:02 abs Exp $
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

.include	"../../devel/pth/buildlink.mk"
.include	"../../x11/gtk/buildlink.mk"
.include	"../../audio/esound/buildlink.mk"
.include	"../../mk/x11.buildlink.mk"

.include "../../mk/bsd.pkg.mk"
