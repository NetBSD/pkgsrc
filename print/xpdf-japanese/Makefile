# $NetBSD: Makefile,v 1.5 2003/03/25 14:28:24 salo Exp $
#

DISTNAME=	xpdf-japanese
PKGNAME=	${DISTNAME}-20020401
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Japanese

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

DIST_SUBDIR=	${PKGNAME_NOREV}
WRKSRC=		${WRKDIR}/${DISTNAME}
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
