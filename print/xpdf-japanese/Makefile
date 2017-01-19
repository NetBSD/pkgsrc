# $NetBSD: Makefile,v 1.24 2017/01/19 18:52:23 agc Exp $
#

DISTNAME=	xpdf-japanese-2011-sep-02
PKGNAME=	xpdf-japanese-20110902
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
MASTER_SITES+=	http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Japanese
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

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
