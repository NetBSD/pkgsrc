# $NetBSD: Makefile,v 1.1.1.1 1999/09/02 17:51:15 dmcmahill Exp $

DISTNAME=	ted-2.5.src
PKGNAME=	ted-2.5
WRKSRC=		${WRKDIR}/Ted-2.5
CATEGORIES=	print
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/

DEPENDS+=	giflib-3.0:../../graphics/giflib
DEPENDS+=       jpeg-6b:../../graphics/jpeg
DEPENDS+=	png-1.0.3:../../graphics/png
DEPENDS+=       tiff-3.4:../../graphics/tiff
DEPENDS+=       xpm-3.4k:../../graphics/xpm

USE_MOTIF=	YES
USE_X11=	YES

MAKE_ENV+=	DEF_PKGDIR='-DPKGDIR=\"${PREFIX}\"' \
		DEF_AFMDIR='-DAFMDIR=\"${PREFIX}/share/Ted/afm\"' \
		DEF_INDDIR='-DINDDIR=\"${PREFIX}/share/Ted/ind\"' \
		DEF_INFODIR='-DINFODIR=\"${PREFIX}/share/doc/Ted\"'

ALL_TARGET=	compile

post-extract:
	@cd ${WRKSRC} ; tar xf tedPackage/TedBindist.tar

post-patch:
	@cd ${WRKSRC}/info ; \
	${SED} -e "s!Ted.afmDirectory:.*!Ted.afmDirectory:${PREFIX}/share/Ted/afm!g" \
	-e "s!Ted.spellToolSystemDicts:.*!Ted.spellToolSystemDicts:${PREFIX}/share/Ted/ind!g" \
	-e "s!Ted.documentFileName:.*!Ted.documentFileName:${PREFIX}/share/doc/Ted/TedDocument.rtf!g" \
	Ted.ad.sample > Ted

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin/Ted
	${INSTALL_DATA_DIR} ${PREFIX}/share/Ted
	${INSTALL_DATA_DIR} ${PREFIX}/share/Ted/afm
	${INSTALL_DATA_DIR} ${PREFIX}/share/Ted/ind
	${INSTALL_DATA} ${FILESDIR}/README.ind ${PREFIX}/share/Ted/ind
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/Ted
	${INSTALL_DATA} ${WRKSRC}/afm/Courier-Bold.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Courier-BoldOblique.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Courier-Oblique.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Courier.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Helvetica-Bold.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Helvetica-BoldOblique.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Helvetica-Oblique.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Helvetica.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Symbol.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Times-Bold.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Times-BoldItalic.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Times-Italic.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/afm/Times-Roman.afm ${PREFIX}/share/Ted/afm
	${INSTALL_DATA} ${WRKSRC}/info/Ted ${PREFIX}/lib/X11/app-defaults
	${INSTALL_DATA} ${WRKSRC}/info/TedDocument.rtf ${PREFIX}/share/doc/Ted

.include "../../mk/bsd.pkg.mk"
