# $NetBSD: Makefile,v 1.21 2012/10/08 13:45:49 asau Exp $
#

DISTNAME=	xpdf-japanese-2004-jul-27
PKGNAME=	xpdf-japanese-20040727
PKGREVISION=	2
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

INSTALLATION_DIRS+=	share/xpdf/japanese/CMap

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/Adobe-Japan1.cidToUnicode \
	    ${WRKSRC}/EUC-JP.unicodeMap ${WRKSRC}/ISO-2022-JP.unicodeMap \
	    ${WRKSRC}/Shift-JIS.unicodeMap ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/japanese
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${DESTDIR}${PREFIX}/share/xpdf/japanese/CMap

.include "../../mk/bsd.pkg.mk"
