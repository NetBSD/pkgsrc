# $NetBSD: Makefile,v 1.27 2023/07/03 13:11:48 wiz Exp $

DISTNAME=	xpdf-japanese-2011-sep-02
PKGNAME=	xpdf-japanese-20110902
PKGREVISION=	1
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-japanese.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Japanese
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02<4:../../print/xpdf

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
