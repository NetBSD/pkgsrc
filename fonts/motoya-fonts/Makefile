# $NetBSD: Makefile,v 1.4 2014/06/01 16:35:36 wiz Exp $
#

DISTNAME=	motoya-fonts-20111115
PKGREVISION=	1
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://source.android.com/
COMMENT=	Motoya L Cider W3 and L Mulberry W3 fonts
LICENSE=	apache-2.0

USE_LANGUAGES=	# none
USE_X11BASE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF \
			${DOCDIR}

INSTALL_FONTS=	MTLc3m.ttf \
		MTLmr3m.ttf

INSTALL_DOCS=	NOTICE

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
