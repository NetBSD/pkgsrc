# $NetBSD: Makefile,v 1.25 2005/05/16 01:15:31 jlam Exp $

DISTNAME=	ted-2.16.src
PKGNAME=	ted-2.16
PKGREVISION=	2
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/	\
		ftp://metalab.unc.edu/pub/packages/editors/ted/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	X11 based WordPad-like word processor

PKG_INSTALLATION_TYPES=	overwrite pkgviews

PKGSRC_USE_TOOLS+=	gtar

WRKSRC=		${WRKDIR}/Ted-2.16
USE_X11BASE=	YES

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind
INFODIR=	${PREFIX}/share/doc/Ted

CONFIGURE_ENV+=	ac_jpeg_includes="${BUILDLINK_PREFIX.jpeg}/include"
CONFIGURE_ENV+=	ac_jpeg_libraries="${BUILDLINK_PREFIX.jpeg}/lib"
CONFIGURE_ENV+=	ac_png_includes="${BUILDLINK_PREFIX.png}/include"
CONFIGURE_ENV+=	ac_png_libraries="${BUILDLINK_PREFIX.png}/lib"
CONFIGURE_ENV+=	ac_tiff_includes="${BUILDLINK_PREFIX.tiff}/include"
CONFIGURE_ENV+=	ac_tiff_libraries="${BUILDLINK_PREFIX.tiff}/lib"
CONFIGURE_ENV+=	ac_xm_includes="${BUILDLINK_PREFIX.openmotif}/include"
CONFIGURE_ENV+=	ac_xm_libraries="${BUILDLINK_PREFIX.openmotif}/lib"
CONFIGURE_ENV+=	ac_xpm_includes="${BUILDLINK_PREFIX.xpm}/include"
CONFIGURE_ENV+=	ac_xpm_libraries="${BUILDLINK_PREFIX.xpm}/lib"
CONFIGURE_ENV+=	ac_zlib_includes="${BUILDLINK_PREFIX.zlib}/include"
CONFIGURE_ENV+=	ac_zlib_libraries="${BUILDLINK_PREFIX.zlib}/lib"

MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_ENV+=	DEF_PKGDIR='-DPKGDIR=\"${PREFIX}\"' \
		DEF_AFMDIR='-DAFMDIR=\"${AFMDIR}\"' \
		DEF_INDDIR='-DINDDIR=\"${INDDIR}\"' \
		DEF_INFODIR='-DDOCUMENT_DIR=\"${INFODIR}\"'

BUILD_TARGET=	compile.shared
INSTALL_TARGET=	install.shared

INSTALLATION_DIRS=	bin lib/X11/app-defaults

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

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/xpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
