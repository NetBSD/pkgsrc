# $NetBSD: Makefile,v 1.19 2006/03/14 01:14:33 jlam Exp $
#

DISTNAME=	xpdf-korean-2005-jul-07
PKGNAME=	xpdf-korean-20050707
PKGREVISION=	1
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

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc
	${ECHO} "displayCIDFontTT	Adobe-Korea1	${PREFIX}/lib/X11/fonts/TTF/batang.ttf" >> ${WRKSRC}/add-to-xpdfrc
	${ECHO} "displayCIDFontTT	Unidocs-Korea1	${PREFIX}/lib/X11/fonts/TTF/batang.ttf" >> ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/korean
	${INSTALL_DATA} ${WRKSRC}/Adobe-Korea1.cidToUnicode \
		${PREFIX}/share/xpdf/korean
	${INSTALL_DATA} ${WRKSRC}/ISO-2022-KR.unicodeMap \
		${PREFIX}/share/xpdf/korean
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/korean/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${PREFIX}/share/xpdf/korean/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
