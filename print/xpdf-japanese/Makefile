# $NetBSD: Makefile,v 1.3 2002/09/19 19:21:39 kei Exp $
#

DISTNAME=	xpdf-japanese
PKGNAME=	${DISTNAME}-20020521
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Japanese

DEPENDS+=	xpdf>=1.00:../../print/xpdf

USE_X11BASE=	yes

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${X11PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/Adobe-Japan1.cidToUnicode \
		${X11PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/EUC-JP.unicodeMap \
		${X11PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/ISO-2022-JP.unicodeMap \
		${X11PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/Shift-JIS.unicodeMap \
		${X11PREFIX}/share/xpdf/japanese
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/japanese/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${X11PREFIX}/share/xpdf/japanese/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
