# $NetBSD: Makefile,v 1.17 2004/11/29 01:03:03 tv Exp $

DISTNAME=	BasiliskII_src_14032003
PKGNAME=	BasiliskII-1.0.20030314
CATEGORIES=	emulators
MASTER_SITES=	http://gwenole.beauchesne.online.fr/basilisk2/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gwenole.beauchesne.online.fr/basilisk2/
COMMENT=	Open Source 68k Macintosh emulator

WRKSRC=		${WRKDIR}/BasiliskII-1.0/src/Unix
USE_BUILDLINK3=	yes
GNU_CONFIGURE=	yes
USE_GNU_TOOLS+=	make
USE_LANGUAGES=	c c++
USE_X11=	yes

CONFIGURE_ARGS+=	--without-gtk \
			--without-esd \
			--disable-fbdev-dga \
			--without-mon

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/BasiliskII
	${INSTALL_DATA} ${WRKSRC}/../../README ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/../../TECH ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/../../TODO ${PREFIX}/share/doc/BasiliskII/

.include "../../mk/bsd.pkg.mk"
