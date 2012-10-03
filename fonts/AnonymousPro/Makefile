# $NetBSD: Makefile,v 1.2 2012/10/03 18:28:15 asau Exp $
#

DISTNAME=	AnonymousPro-1.001
CATEGORIES=	fonts
MASTER_SITES=	http://www.ms-studio.com/FontSales/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.ms-studio.com/FontSales/anonymouspro.html
COMMENT=	Fixed width Sans designed especially for Coders
LICENSE=	open-font-license

#WRKSRC=		${WRKDIR}/AnonymousPro-1.001
USE_LANGUAGES=	# none

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	lib/X11/fonts/TTF ${DOCSDIR}

FONTDIR=	${PREFIX}/lib/X11/fonts/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	AnonymousProB.ttf \
		AnonymousProBI.ttf \
		AnonymousProI.ttf \
		AnonymousPro.ttf
INSTALL_DOCS=   FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt

post-extract:
	cd ${WRKSRC} && for i in *.ttf; do \
		j=`echo $$i | sed "s/ //g"`; \
		mv "$$i" "$$j"; done

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile:Q} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
