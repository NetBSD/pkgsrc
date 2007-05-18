# $NetBSD: Makefile,v 1.1.1.1 2007/05/18 06:39:27 wiz Exp $
#

DISTNAME=	tesseract-1.04b
CATEGORIES=	graphics
MASTER_SITES=	http://tesseract-ocr.googlecode.com/files/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/tesseract-ocr/
COMMENT=	Commercial quality open source OCR engine

PKG_DESTDIR_SUPPORT=user-destdir

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
WRKSRC=		${WRKDIR}/tesseract-1.04

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/tesseract.sh \
		> ${WRKSRC}/tesseract.sh

post-install:
	${INSTALL_LIB_DIR} ${DESTDIR}${PREFIX}/libexec
	${MV} ${DESTDIR}${PREFIX}/bin/tesseract ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/tesseract.sh ${DESTDIR}${PREFIX}/bin/tesseract
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/doc/tesseract
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tesseract
	${INSTALL_DATA_DIR} ${DESTDIR}${PREFIX}/share/tesseract
	${INSTALL_DATA} ${WRKSRC}/phototest.tif ${DESTDIR}${PREFIX}/share/tesseract

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
