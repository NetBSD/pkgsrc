# $NetBSD: Makefile,v 1.24 2017/01/19 18:52:22 agc Exp $
#

DISTNAME=	xpdf-chinese-simplified-2011-sep-02
PKGNAME=	xpdf-chinese-simplified-20110902
PKGREVISION=	1
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/
MASTER_SITES+=	http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Chinese (Simplified)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf

WRKSRC=		${WRKDIR}/xpdf-chinese-simplified
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/chinese-simplified/CMap

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/Adobe-GB1.cidToUnicode \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/EUC-CN.unicodeMap \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/GBK.unicodeMap \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/ISO-2022-CN.unicodeMap \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-simplified
	${INSTALL_DATA} ${WRKSRC}/CMap/* \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-simplified/CMap
	${INSTALL_DATA} ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-simplified

.include "../../mk/bsd.pkg.mk"
