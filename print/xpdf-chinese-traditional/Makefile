# $NetBSD: Makefile,v 1.13 2004/07/28 11:55:08 wiz Exp $
#

DISTNAME=	xpdf-chinese-traditional-2004-jul-27
PKGNAME=	xpdf-chinese-traditional-20040727
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/ \
		http://gd.tuwien.ac.at/publishing/xpdf/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	Xpdf support files for Chinese (Traditional)

DEPENDS+=	xpdf>=2.02:../../print/xpdf

USE_PKGINSTALL=	yes

WRKSRC=		${WRKDIR}/xpdf-chinese-traditional
NO_CONFIGURE=	yes
NO_BUILD=	yes

DEINSTALL_EXTRA_TMPL+=	${.CURDIR}/DEINSTALL

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' -e 's/Arhpic/Arphic/g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA} ${WRKSRC}/Adobe-CNS1.cidToUnicode \
		${PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA} ${WRKSRC}/Big5.unicodeMap \
		${PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA_DIR} ${PREFIX}/share/xpdf/chinese-traditional/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${PREFIX}/share/xpdf/chinese-traditional/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
