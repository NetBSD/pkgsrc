# $NetBSD: Makefile,v 1.3 2002/09/19 19:21:39 kei Exp $
#

DISTNAME=	xpdf-chinese-traditional
PKGNAME=	${DISTNAME}-20020521
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.foolabs.com/pub/xpdf/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.foolabs.com/xpdf/
COMMENT=	xpdf support files for Chinese (Traditional)

DEPENDS+=	xpdf>=1.00:../../print/xpdf

USE_X11BASE=	yes

DIST_SUBDIR=	${PKGNAME}
WRKSRC=		${WRKDIR}/${DISTNAME}
NO_CONFIGURE=	yes
NO_BUILD=	yes

post-patch:
	${MV} ${WRKSRC}/add-to-xpdfrc ${WRKSRC}/add-to-xpdfrc.orig
	${SED} -e 's:/usr/local:'${X11PREFIX}':g' -e 's/Arhpic/Arphic/g' < ${WRKSRC}/add-to-xpdfrc.orig > ${WRKSRC}/add-to-xpdfrc

do-install:
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA} ${WRKSRC}/Adobe-CNS1.cidToUnicode \
		${X11PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA} ${WRKSRC}/Big5.unicodeMap \
		${X11PREFIX}/share/xpdf/chinese-traditional
	${INSTALL_DATA_DIR} ${X11PREFIX}/share/xpdf/chinese-traditional/CMap
	${INSTALL_DATA} ${WRKSRC}/CMap/* ${X11PREFIX}/share/xpdf/chinese-traditional/CMap

post-install:
	${CAT} ${WRKSRC}/add-to-xpdfrc >> ${PKG_SYSCONFDIR}/xpdfrc

.include "../../mk/bsd.pkg.mk"
