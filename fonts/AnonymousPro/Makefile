# $NetBSD: Makefile,v 1.7 2017/08/01 14:58:57 wiz Exp $
#

DISTNAME=	AnonymousPro-1.002
CATEGORIES=	fonts
MASTER_SITES=	http://www.marksimonson.com/assets/content/fonts/
EXTRACT_SUFX=	.zip

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.marksimonson.com/fonts/view/anonymous-pro
COMMENT=	Fixed width Sans designed especially for Coders
LICENSE=	ofl-v1.1

WRKSRC=		${WRKDIR}/AnonymousPro-1.002.001
USE_LANGUAGES=	# none

NO_CONFIGURE=	YES
NO_BUILD=	YES

DOCSDIR=	${PREFIX}/share/doc/${PKGBASE}

INSTALLATION_DIRS=	share/fonts/X11/TTF ${DOCSDIR}

FONTDIR=	${PREFIX}/share/fonts/X11/TTF
FONTS_DIRS.ttf=	${FONTDIR}

INSTALL_FONTS=	AnonymousProB.ttf \
		AnonymousProBI.ttf \
		AnonymousProI.ttf \
		AnonymousPro.ttf
INSTALL_DOCS=   FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt

post-extract:
	cd ${WRKSRC} && for i in *.ttf; do \
		j=`${ECHO} $$i | sed "s/ //g"`; \
		mv "$$i" "$$j"; done

do-install:
.for fontfile in ${INSTALL_FONTS}
	${INSTALL_DATA} ${WRKSRC}/${fontfile:Q} ${DESTDIR}${FONTDIR}
.endfor
.for docfile in ${INSTALL_DOCS}
	${INSTALL_DATA} ${WRKSRC}/${docfile} ${DESTDIR}${DOCSDIR}
.endfor

.include "../../mk/bsd.pkg.mk"
