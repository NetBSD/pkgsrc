# $NetBSD: Makefile,v 1.25 2004/07/27 13:40:36 adam Exp $

DISTNAME=	scummvm-0.6.1-src
PKGNAME=	scummvm-0.6.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=scummvm/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://scummvm.sourceforge.net/
COMMENT=	LucasArts Script Creation Utility for Maniac Mansion

WRKSRC=		${WRKDIR}/${PKGNAME}

USE_BUILDLINK3=		yes
USE_DIRS+=		xdg-1.1
USE_GNU_TOOLS+=		make
USE_X11=		yes
HAS_CONFIGURE=		yes

UNLIMIT_RESOURCES=	datasize

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/scummvm
	${INSTALL_PROGRAM} ${WRKSRC}/scummvm ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scummvm.6 ${PREFIX}/man/man6
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/scummvm
	${INSTALL_DATA_DIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/scummvm.xpm ${PREFIX}/share/pixmaps

.include "../../audio/libmad/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../devel/SDL/buildlink3.mk"
.include "../../multimedia/libmpeg2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
