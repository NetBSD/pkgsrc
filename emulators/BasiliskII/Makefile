# $NetBSD: Makefile,v 1.22 2005/07/01 12:34:32 adam Exp $

DISTNAME=	BasiliskII_src_22032005
PKGNAME=	BasiliskII-1.0.20050322
CATEGORIES=	emulators
MASTER_SITES=	http://gwenole.beauchesne.online.fr/basilisk2/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://gwenole.beauchesne.online.fr/basilisk2/
COMMENT=	Open Source 68k Macintosh emulator

WRKSRC=		${WRKDIR}/BasiliskII-1.0/src/Unix
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-fbdev-dga
CONFIGURE_ARGS+=	--enable-addressing=banks
CONFIGURE_ARGS+=	--without-mon

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/BasiliskII
	${INSTALL_DATA} ${WRKSRC}/../../README ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/../../TECH ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/../../TODO ${PREFIX}/share/doc/BasiliskII/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
