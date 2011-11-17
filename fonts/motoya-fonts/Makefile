# $NetBSD: Makefile,v 1.2 2011/11/17 20:47:13 ryoon Exp $
#

DISTNAME=	motoya-fonts-20111115
CATEGORIES=	fonts japanese
MASTER_SITES=	${MASTER_SITE_LOCAL}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://source.android.com/
COMMENT=	Motoya L Cider W3 and L Mulberry W3 fonts
LICENSE=	apache-2.0

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# none
USE_X11BASE=	YES
NO_BUILD=	YES

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF \
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
