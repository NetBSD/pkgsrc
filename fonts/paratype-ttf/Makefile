# $NetBSD: Makefile,v 1.3 2017/08/01 14:58:58 wiz Exp $

DISTNAME=	paratype-ttf-20140616
CATEGORIES=	fonts
MASTER_SITES=	http://www.paratype.com/uni/public/
DISTFILES=	PTSans.zip PTSerif.zip PTMono.zip
DIST_SUBDIR=	${DISTNAME}
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.paratype.com/public/
COMMENT=	Public Fonts for Minority Languages of Russia
LICENSE=	paratype

WRKSRC=		${WRKDIR}
USE_LANGUAGES=	# none

FONTS_DIRS.ttf=		${PREFIX}/share/fonts/X11/TTF
INSTALLATION_DIRS+=	share/doc/paratype-ttf share/fonts/X11/TTF

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/*txt ${DESTDIR}${PREFIX}/share/doc/paratype-ttf
	${INSTALL_DATA} ${WRKSRC}/*ttf ${DESTDIR}${PREFIX}/share/fonts/X11/TTF

.include "../../mk/bsd.pkg.mk"
