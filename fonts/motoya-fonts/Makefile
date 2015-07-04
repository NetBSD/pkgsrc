# $NetBSD: Makefile,v 1.5 2015/07/04 16:18:33 joerg Exp $
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
