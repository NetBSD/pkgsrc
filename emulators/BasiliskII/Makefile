# $NetBSD: Makefile,v 1.31 2007/06/12 12:51:07 joerg Exp $

DISTNAME=	BasiliskII_src_01052006
PKGNAME=	BasiliskII-1.0.20060501
PKGREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://gwenole.beauchesne.info/projects/basilisk2/files/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://gwenole.beauchesne.info/projects/basilisk2/
COMMENT=	Open Source 68k Macintosh emulator

WRKSRC=			${WRKDIR}/BasiliskII-1.0
USE_LANGUAGES=		c c++
USE_TOOLS+=		gmake
GNU_CONFIGURE=		yes
CONFIGURE_DIRS=		src/Unix
CONFIGURE_ARGS+=	--disable-fbdev-dga
CONFIGURE_ARGS+=	--enable-addressing=banks
CONFIGURE_ARGS+=	--without-mon
BUILD_DIRS=		${CONFIGURE_DIRS}

.include "options.mk"

CXXFLAGS+=-g -O0

post-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/BasiliskII
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/TECH ${PREFIX}/share/doc/BasiliskII/
	${INSTALL_DATA} ${WRKSRC}/TODO ${PREFIX}/share/doc/BasiliskII/

.include "../../converters/libiconv/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
