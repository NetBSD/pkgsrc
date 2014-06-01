# $NetBSD: Makefile,v 1.2 2014/06/01 16:35:35 wiz Exp $
#

PKGNAME=	jsMath-fonts-20090709
DISTNAME=	TeX-fonts-linux
PKGREVISION=	1
CATEGORIES=	fonts
MASTER_SITES=	http://www.math.union.edu/~dpvc/jsMath/download/
EXTRACT_SUFX=	.tgz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.math.union.edu/~dpvc/jsMath/
COMMENT=	Fonts for jsMath
#LICENSE=	no-commercial-use? unclear; probably whatever the corresponding TeX font license is

DIST_SUBDIR=	${PKGNAME_NOREV}

USE_LANGUAGES=	# none

FONTDIR=		${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf+=	${FONTDIR}
INSTALLATION_DIRS+=	${FONTDIR}

do-build:

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${DESTDIR}${FONTDIR}

.include "../../mk/bsd.pkg.mk"
