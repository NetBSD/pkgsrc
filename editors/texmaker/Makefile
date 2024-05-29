# $NetBSD: Makefile,v 1.139 2024/05/29 16:32:25 adam Exp $

DISTNAME=	texmaker-5.1.4
PKGREVISION=	6
CATEGORIES=	editors
MASTER_SITES=	http://www.xm1math.net/texmaker/
EXTRACT_SUFX=	.tar.bz2
EXTRACT_USING=	bsdtar

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.xm1math.net/texmaker/
COMMENT=	LaTeX editor and front end
LICENSE=	gnu-gpl-v2

USE_TOOLS+=	pkg-config
USE_LANGUAGES=	c++ c

INSTALL_MAKE_FLAGS+=	INSTALL_ROOT=${DESTDIR}

do-configure:
	cd ${WRKSRC} && env ${CONFIGURE_ENV} \
	${QTDIR}/bin/qmake PREFIX=${PREFIX} texmaker.pro \
		DESKTOPDIR=${PREFIX}/share/applications \
		ICONDIR=${PREFIX}/share/pixmaps \
		METAINFODIR=${PREFIX}/share/appdata

post-extract:
	${CP} ${FILESDIR}/fxge_pkgsrcfonts.inc ${WRKSRC}/pdfium/core/fxge
	${CP} ${FILESDIR}/fxge_x11fonts.inc ${WRKSRC}/pdfium/core/fxge
	${CP} ${FILESDIR}/fgas_stdfontmgr_pkgsrcfonts.inc \
		${WRKSRC}/pdfium/xfa/fgas/font
	${CP} ${FILESDIR}/fgas_stdfontmgr_x11fonts.inc \
		${WRKSRC}/pdfium/xfa/fgas/font

SUBST_CLASSES+=		fonts
SUBST_STAGE.fonts=	pre-configure
SUBST_FILES.fonts+=	pdfium/core/fxge/fxge_pkgsrcfonts.inc
SUBST_FILES.fonts+=	pdfium/core/fxge/fxge_x11fonts.inc
SUBST_FILES.fonts+=	pdfium/xfa/fgas/font/fgas_stdfontmgr_pkgsrcfonts.inc
SUBST_FILES.fonts+=	pdfium/xfa/fgas/font/fgas_stdfontmgr_x11fonts.inc
SUBST_VARS.fonts+=	PREFIX
SUBST_VARS.fonts+=	X11BASE

DEPENDS+=	xdg-utils-[0-9]*:../../misc/xdg-utils

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/hunspell/buildlink3.mk"
.include "../../x11/qt5-qtdeclarative/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
