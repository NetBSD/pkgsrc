# $NetBSD: Makefile,v 1.29 2020/03/20 11:58:15 nia Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	xdvik-22.87.03
PKGREVISION=	3
CATEGORIES=	print

HOMEPAGE=	http://xdvi.sourceforge.net/
COMMENT=	Previewer for DVI files

BUILD_DEPENDS+=	tex-tetex-[0-9]*:../../print/tex-tetex
BUILD_DEPENDS+=	tex-xdvi-[0-9]*:../../print/tex-xdvi
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	kpathsea>=6.2.1:../../print/kpathsea

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/xdvik

USE_TOOLS+=	gs:run

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

GNU_CONFIGURE_STRICT=	no # texk/xdvik/squeeze/configure
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-xdvi-x-toolkit=xaw
CONFIGURE_ARGS+=	--with-default-dvips-path=${PREFIX}/bin/dvips
CONFIGURE_ARGS+=	--with-default-ps2pdf-path=${PREFIX}/bin/ps2pdf

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdvi
CONF_FILES=	${PREFIX}/share/examples/xdvik/XDvi \
		${PKG_SYSCONFDIR}/xdvi/XDvi

BUILD_DEFS+=	PAPERSIZE

INSTALLATION_DIRS+=	share/examples/xdvik

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../mk/bsd.prefs.mk"

.if ${PAPERSIZE} == "Letter"
XDVI_PAPERSIZE=	us
.else
XDVI_PAPERSIZE=	a4
.endif

post-build:
	${RM} ${WRKSRC}/texmf/XDvi
	${MKDIR} ${WRKSRC}/texmf/xdvi
	${CP} ${PREFIX}/share/texmf-dist/xdvi/XDvi ${WRKSRC}/texmf/xdvi
	${SETENV} TEXMFCONFIG=${PREFIX}/share/texmf \
		TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		${PREFIX}/bin/texconfig xdvi paper ${XDVI_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/xdvi/XDvi \
		${DESTDIR}${PREFIX}/share/examples/xdvik

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
