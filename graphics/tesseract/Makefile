# $NetBSD: Makefile,v 1.12 2013/01/26 21:38:01 adam Exp $
#

DISTNAME=	tesseract-2.04
PKGREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://tesseract-ocr.googlecode.com/files/
DISTFILES+=	${DISTNAME}.tar.gz
.for l in deu eng fra ita nld spa
DISTFILES+=	tesseract-2.00.${l}.tar.gz
.endfor

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://code.google.com/p/tesseract-ocr/
COMMENT=	Commercial quality open source OCR engine
LICENSE=	apache-2.0

INSTALLATION_DIRS=	libexec share/doc/tesseract share/tesseract

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake pax

post-extract:
	${RM} ${WRKSRC}/java/makefile

post-build:
	${SED} -e "s,@PREFIX@,${PREFIX}," ${FILESDIR}/tesseract.sh \
		> ${WRKSRC}/tesseract.sh

post-install:
	${MV} ${DESTDIR}${PREFIX}/bin/tesseract ${DESTDIR}${PREFIX}/libexec
	${INSTALL_SCRIPT} ${WRKSRC}/tesseract.sh ${DESTDIR}${PREFIX}/bin/tesseract
	${INSTALL_DATA} ${WRKSRC}/README ${DESTDIR}${PREFIX}/share/doc/tesseract
	${INSTALL_DATA} ${WRKSRC}/phototest.tif ${DESTDIR}${PREFIX}/share/tesseract
	cd ${WRKDIR}/tessdata && ${PAX} -rw * ${DESTDIR}${PREFIX}/share/tessdata
	chmod a-x ${DESTDIR}${PREFIX}/share/tessdata/*.*

.include "../../graphics/tiff/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
