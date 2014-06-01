# $NetBSD: Makefile,v 1.3 2014/06/01 16:35:37 wiz Exp $
#

DISTNAME=	uralic-ttf-0.0.20040603
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.peoples.org.ru/font/
DISTFILES=	BookmanUralic.zip ChanceryUralic.zip GothicUralic.zip \
		MonoUralic.zip PalladioUralic.zip RomanUralic.zip \
		SansUralic.zip SansCondUralic.zip SchoolbookUralic.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://peoples.org.ru/eng_uralic.html
COMMENT=	Font for Uralic languages with Russian-based writing systems
LICENSE=	gnu-gpl-v2

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.TTF ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
