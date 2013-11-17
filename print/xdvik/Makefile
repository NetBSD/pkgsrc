# $NetBSD: Makefile,v 1.14 2013/11/17 16:56:47 minskim Exp $

DISTNAME=	texlive-20130530-source
PKGNAME=	xdvik-22.86
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xdvi.sourceforge.net/
COMMENT=	Previewer for DVI files

CONFLICTS+=	teTeX-bin<3.0nb25
BUILD_DEPENDS+=	tex-texconfig-[0-9]*:../../print/tex-texconfig
BUILD_DEPENDS+=	tex-xdvi-[0-9]*:../../print/tex-xdvi
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	kpathsea>=6.0.1:../../print/kpathsea

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/xdvik

USE_TOOLS+=	gs:run

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

FIND_PREFIX:=	TEX_XDVI_PREFIX=tex-xdvi
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
		--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-xdvi-x-toolkit=xaw
CONFIGURE_ARGS+=	--with-default-dvips-path=${LOCALBASE}/bin/dvips
CONFIGURE_ARGS+=	--with-default-ps2pdf-path=${LOCALBASE}/bin/ps2pdf

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

.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

post-build:
	${MKDIR} -p ${WRKSRC}/texmf/xdvi
	${CP} ${LOCALBASE}/share/texmf-dist/xdvi/XDvi ${WRKSRC}/texmf/xdvi
	env TEXMFCONFIG=${LOCALBASE}/share/texmf \
		TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		${LOCALBASE}/bin/texconfig xdvi paper ${XDVI_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/xdvi/XDvi \
		${DESTDIR}${PREFIX}/share/examples/xdvik

.include "../../mk/bsd.pkg.mk"
