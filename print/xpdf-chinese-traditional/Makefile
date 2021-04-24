# $NetBSD: Makefile,v 1.24 2021/04/24 11:09:49 wiz Exp $

DISTNAME=	xpdf-chinese-traditional-2011-sep-02
PKGNAME=	xpdf-chinese-traditional-20110902
PKGREVISION=	1
CATEGORIES=	print
#MASTER_SITES=	https://dl.xpdfreader.com/xpdf-chinese-traditional.tar.gz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xpdfreader.com/
COMMENT=	Xpdf support files for Chinese (Traditional)
LICENSE=	gnu-gpl-v2 OR gnu-gpl-v3

DEPENDS+=	xpdf>=2.02:../../print/xpdf


WRKSRC=		${WRKDIR}/xpdf-chinese-traditional
NO_CONFIGURE=	yes
NO_BUILD=	yes

INSTALLATION_DIRS+=	share/xpdf/chinese-traditional/CMap

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${PREFIX}':g' -e 's/Arhpic/Arphic/g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA} ${WRKSRC}/Adobe-CNS1.cidToUnicode \
	    ${WRKSRC}/Big5.unicodeMap ${WRKSRC}/add-to-xpdfrc \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA} ${WRKSRC}/CMap/* \
	    ${DESTDIR}${PREFIX}/share/xpdf/chinese-traditional/CMap

.include "../../mk/bsd.pkg.mk"
