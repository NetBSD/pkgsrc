# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:26 asau Exp $

DISTNAME=	# empty
PKGNAME=	kiloji-ttf-2.1.0
CATEGORIES=	fonts japanese
MASTER_SITES=	http://www.ez0.net/wp-content/uploads/distribution/font/kiloji/
EXTRACT_SUFX=	.zip
DISTFILES=	kiloji_2.1.0.zip \
		kiloji_p2.1.0.zip \
		kiloji_d2.1.0.zip \
		kiloji_b2.1.0.zip

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	http://www.ez0.net/distribution/font/kiloji/
COMMENT=	JIS X 0208 Japanese script fonts made by kilo
LICENSE=	modified-bsd # with some difference

USE_X11BASE=	yes
NO_CONFIGURE=	yes
NO_BUILD=	yes

DIST_SUBDIR=	kiloji-ttf
FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

DOCDIR=		${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	${FONTDIR} ${DOCDIR}

INSTALL_FONTS=	kiloji.ttf \
		kiloji_b.ttf \
		kiloji_d.ttf \
		kiloji_p.ttf

INSTALL_DOCS=	Collecting.txt \
		License.txt

do-install:
.for f in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${FONTDIR}
.endfor
.for f in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DESTDIR}${DOCDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
