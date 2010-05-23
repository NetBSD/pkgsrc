# $NetBSD: Makefile,v 1.27 2010/05/23 18:46:27 adam Exp $

DISTNAME=	hatari-1.3.1
CATEGORIES=	emulators
MASTER_SITES=	http://download.berlios.de/hatari/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://hatari.berlios.de/
COMMENT=	Atari ST emulator

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes

INSTALLATION_DIRS+=	share/doc/hatari

post-install:
	cd ${WRKSRC} && ${INSTALL_DATA} *.txt \
			${DESTDIR}${PREFIX}/share/doc/hatari
	cd ${WRKSRC}/doc && ${INSTALL_DATA} *.txt *.html \
			${DESTDIR}${PREFIX}/share/doc/hatari

.include "../../devel/SDL/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../mk/bsd.pkg.mk"
