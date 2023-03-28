# $NetBSD: Makefile,v 1.1 2023/03/28 13:27:37 joerg Exp $
#

DISTNAME=	GentiumPlus-6.200
PKGNAME=	gentiumplus-ttf-6.200
CATEGORIES=	fonts
MASTER_SITES=	https://software.sil.org/downloads/r/gentium/
EXTRACT_SUFX=	.zip

MAINTAINER=	joerg@NetBSD.org
HOMEPAGE=	https://software.sil.org/gentium/
COMMENT=	Modern international font for Latin, Cyrillic and Greek scripts
LICENSE=	ofl-v1.1


NO_CONFIGURE=	YES
NO_BUILD=	YES

FONTS_DIRS.ttf+=	${PREFIX}/share/fonts/X11/TTF

INSTALLATION_DIRS=	share/fonts/X11/TTF

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTS_DIRS.ttf}

.include "../../mk/bsd.pkg.mk"
