# $NetBSD: Makefile,v 1.9 2002/04/09 02:13:37 markd Exp $

DISTNAME=	ted-2.11.src
PKGNAME=	ted-2.11
WRKSRC=		${WRKDIR}/Ted-2.11
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/	\
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	X11 based WordPad-like word processor

USE_X11BASE=	YES

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind
INFODIR=	${PREFIX}/share/doc/Ted

MAKE_ENV+=	DEF_PKGDIR='-DPKGDIR=\"${PREFIX}\"' \
		DEF_AFMDIR='-DAFMDIR=\"${AFMDIR}\"' \
		DEF_INDDIR='-DINDDIR=\"${INDDIR}\"' \
		DEF_INFODIR='-DINFODIR=\"${INFODIR}\"'

ALL_TARGET=	compile.shared
INSTALL_TARGET=	install.shared

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

post-patch:
	@cd ${WRKSRC}/Ted ; \
	${SED}	-e "s!Ted.afmDirectory:.*!Ted.afmDirectory:${AFMDIR}!g" \
		-e "s!Ted.spellToolSystemDicts:.*!Ted.spellToolSystemDicts:${INDDIR}!g" \
		-e "s!Ted.documentFileName:.*!Ted.documentFileName:${INFODIR}/TedDocument-en_US.rtf!g" \
		Ted.ad.sample > Ted.ad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${PREFIX}/bin/Ted
	${INSTALL_DATA_DIR} ${AFMDIR}
	${INSTALL_DATA} \
		${WRKSRC}/afm/Courier-Bold.afm \
		${WRKSRC}/afm/Courier-BoldOblique.afm \
		${WRKSRC}/afm/Courier-Oblique.afm \
		${WRKSRC}/afm/Courier.afm \
		${WRKSRC}/afm/Helvetica-Bold.afm \
		${WRKSRC}/afm/Helvetica-BoldOblique.afm \
		${WRKSRC}/afm/Helvetica-Oblique.afm \
		${WRKSRC}/afm/Helvetica.afm \
		${WRKSRC}/afm/Symbol.afm \
		${WRKSRC}/afm/Times-Bold.afm \
		${WRKSRC}/afm/Times-BoldItalic.afm \
		${WRKSRC}/afm/Times-Italic.afm \
		${WRKSRC}/afm/Times-Roman.afm \
		${AFMDIR}
	${INSTALL_DATA_DIR} ${INDDIR}
	${INSTALL_DATA} ${FILESDIR}/README.ind ${INDDIR}
	${INSTALL_DATA_DIR} ${INFODIR}
	${INSTALL_DATA} ${WRKSRC}/Ted/TedDocument-en_US.rtf ${INFODIR}
	${INSTALL_DATA}	${WRKSRC}/Ted/Ted.ad ${PREFIX}/lib/X11/app-defaults/Ted

.include "../../graphics/jpeg/buildlink.mk"
.include "../../graphics/png/buildlink.mk"
.include "../../graphics/tiff/buildlink.mk"
.include "../../graphics/xpm/buildlink.mk"
.include "../../mk/motif.buildlink.mk"
.include "../../mk/bsd.pkg.mk"
