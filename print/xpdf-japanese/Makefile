# $NetBSD: Makefile,v 1.19 2006/03/14 01:14:33 jlam Exp $
#

DISTNAME=	xpdf-japanese-2004-jul-27
PKGNAME=	xpdf-japanese-20040727
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Japanese

DEPENDS+=	xpdf>=2.02:../../print/xpdf


WRKSRC=		${WRKDIR}/xpdf-japanese
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/Adobe-Japan1.cidToUnicode \
		${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/EUC-JP.unicodeMap \
		${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/ISO-2022-JP.unicodeMap \
		${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/Shift-JIS.unicodeMap \
		${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/japanese/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${PREFIX}/share/xpdf/japanese/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
