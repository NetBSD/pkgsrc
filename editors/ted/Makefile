# $NetBSD: Makefile,v 1.51 2012/09/28 09:10:10 jperkin Exp $

DISTNAME=	ted-2.21.src
PKGNAME=	${DISTNAME:S/.src//}
PKGREVISION=	5
CATEGORIES=	editors
MASTER_SITES=	ftp://ftp.nluug.nl/pub/editors/ted/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.nllgg.nl/Ted/
COMMENT=	X11 based WordPad-like word processor
LICENSE=	gnu-gpl-v2

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	c c++
USE_TOOLS+=	gtar
MAKE_JOBS_SAFE=	no

WRKSRC=		${WRKDIR}/Ted-2.21

AFMDIR=		${PREFIX}/share/Ted/afm
INDDIR=		${PREFIX}/share/Ted/ind
INFODIR=	${PREFIX}/share/doc/Ted

CONFIGURE_ENV+=	ac_jpeg_includes="${JPEGBASE}/include"
CONFIGURE_ENV+=	ac_jpeg_libraries="${JPEGBASE}/lib"
CONFIGURE_ENV+=	ac_png_includes="${BUILDLINK_PREFIX.png}/include"
CONFIGURE_ENV+=	ac_png_libraries="${BUILDLINK_PREFIX.png}/lib"
CONFIGURE_ENV+=	ac_tiff_includes="${BUILDLINK_PREFIX.tiff}/include"
CONFIGURE_ENV+=	ac_tiff_libraries="${BUILDLINK_PREFIX.tiff}/lib"
CONFIGURE_ENV+=	ac_xm_includes="${BUILDLINK_PREFIX.openmotif}/include"
CONFIGURE_ENV+=	ac_xm_libraries="${BUILDLINK_PREFIX.openmotif}/lib"
CONFIGURE_ENV+=	ac_xpm_includes="${BUILDLINK_PREFIX.libXpm}/include"
CONFIGURE_ENV+=	ac_xpm_libraries="${BUILDLINK_PREFIX.libXpm}/lib"
CONFIGURE_ENV+=	ac_zlib_includes="${BUILDLINK_PREFIX.zlib}/include"
CONFIGURE_ENV+=	ac_zlib_libraries="${BUILDLINK_PREFIX.zlib}/lib"

LDFLAGS.SunOS+=	-liconv
LDFLAGS.DragonFly+=	-lXft -lfontconfig

MAKE_FLAGS+=	CONFIGURE_OPTIONS=--x-libraries=${X11BASE}/lib\ --with-MOTIF

MAKE_ENV+=	${CONFIGURE_ENV}
MAKE_ENV+=	DEF_PKGDIR='-DPKGDIR=\"${PREFIX}\"' \
		DEF_AFMDIR='-DAFMDIR=\"${AFMDIR}\"' \
		DEF_INDDIR='-DINDDIR=\"${INDDIR}\"' \
		DEF_INFODIR='-DDOCUMENT_DIR=\"${INFODIR}\"'

BUILD_TARGET=	compile.shared
INSTALL_TARGET=	install.shared

INSTALLATION_DIRS=	bin lib/X11/app-defaults ${AFMDIR} ${INDDIR} ${INFODIR}

post-extract:
	@cd ${WRKSRC} ; ${GTAR} xf tedPackage/TedBindist.tar

post-patch:
	@cd ${WRKSRC}/Ted ; \
	${SED}	-e "s!Ted.afmDirectory:.*!Ted.afmDirectory:${AFMDIR}!g" \
		-e "s!Ted.spellToolSystemDicts:.*!Ted.spellToolSystemDicts:${INDDIR}!g" \
		-e "s!Ted.documentFileName:.*!Ted.documentFileName:${INFODIR}/TedDocument-en_US.rtf!g" \
		Ted.ad.sample > Ted.ad

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/Ted/Ted ${DESTDIR}${PREFIX}/bin/Ted
	${INSTALL_DATA} ${WRKSRC}/Ted/afm/*.afm ${DESTDIR}${AFMDIR}
	${INSTALL_DATA} ${FILESDIR}/README.ind ${DESTDIR}${INDDIR}
	${INSTALL_DATA} ${WRKSRC}/Ted/TedDocument-en_US.rtf ${DESTDIR}${INFODIR}
	${INSTALL_DATA}	${WRKSRC}/Ted/Ted.ad \
		${DESTDIR}${PREFIX}/lib/X11/app-defaults/Ted

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/pcre/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/motif.buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
