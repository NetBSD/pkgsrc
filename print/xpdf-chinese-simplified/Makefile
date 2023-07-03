# $NetBSD: Makefile,v 1.27 2023/07/03 13:11:47 wiz Exp $

DISTNAME=	xpdf-chinese-simplified-2011-sep-02
PKGNAME=	xpdf-chinese-simplified-20110902
PKGREVISION=	1
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-chinese-simplified.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Chinese (Simplified)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02<4:../../print/xpdf

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
