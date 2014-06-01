# $NetBSD: Makefile,v 1.22 2014/06/01 18:07:15 wiz Exp $

DISTNAME=	xpdf-korean-2005-jul-07
PKGNAME=	xpdf-korean-20050707
PKGREVISION=	3
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Korean

DEPENDS+=	xpdf>=2.02:../../print/xpdf
DEPENDS+=	baekmuk-ttf>=1.0:../../fonts/baekmuk-ttf

WRKSRC=		${WRKDIR}/xpdf-korean
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/korean/CMap

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc
	${ECHO} "displayCIDFontTT	Adobe-Korea1	${PREFIX}/share/fonts/X11/TTF/batang.ttf" >> ${WRKSRC}/add-to-xpdfrc
	${ECHO} "displayCIDFontTT	Unidocs-Korea1	${PREFIX}/share/fonts/X11/TTF/batang.ttf" >> ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/Adobe-Korea1.cidToUnicode \
	    ${WRKSRC}/ISO-2022-KR.unicodeMap ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/korean
	${INSTALL_DATA} ${WRKSRC}/CMap/* \
	    ${DESTDIR}${PREFIX}/share/xpdf/korean/CMap

.include "../../mk/bsd.pkg.mk"
