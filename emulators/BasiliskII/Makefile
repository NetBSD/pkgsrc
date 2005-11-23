# $NetBSD: Makefile,v 1.25 2005/11/23 12:17:56 adam Exp $

DISTNAME=	BasiliskII_src_22112005
PKGNAME=	BasiliskII-1.0.20051122
CATEGORIES=	emulators
MASTER_SITES=	http://www.gibix.net/projects/basilisk2/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.gibix.net/projects/basilisk2/
COMMENT=	Open Source 68k Macintosh emulator

WRKSRC=			${WRKDIR}/BasiliskII-1.0
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src/Unix
CONFIGURE_ARGS+=	--disable-fbdev-dga
CONFIGURE_ARGS+=	--enable-addressing=banks
CONFIGURE_ARGS+=	--without-mon
# disable gnome support, or configure will break if gnome-libs is installed
CONFIGURE_ENV+=		ac_cv_path_GNOME_CONFIG=no
BUILD_DIRS=		${CONFIGURE_DIRS}

.include "options.mk"

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/BasiliskII
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/TECH ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/BasiliskII/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
