# $NetBSD: Makefile,v 1.21 2016/06/16 04:06:20 markd Exp $

DISTNAME=	texlive-20160523-source
PKGNAME=	xdvik-22.87.03
CATEGORIES=	print
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2016/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xdvi.sourceforge.net/
COMMENT=	Previewer for DVI files

CONFLICTS+=	teTeX-bin<3.0nb25
BUILD_DEPENDS+=	tex-texconfig-[0-9]*:../../print/tex-texconfig
BUILD_DEPENDS+=	tex-xdvi-[0-9]*:../../print/tex-xdvi
DEPENDS+=	dvipsk-[0-9]*:../../print/dvipsk
DEPENDS+=	kpathsea>=6.2.1:../../print/kpathsea

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/xdvik

USE_TOOLS+=	gs:run

MAKE_JOBS_SAFE=	no

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-kpathsea
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
.include "../../x11/libXi/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

post-build:
	${RM} ${WRKSRC}/texmf/XDvi
	${MKDIR} -p ${WRKSRC}/texmf/xdvi
	${CP} ${LOCALBASE}/share/texmf-dist/xdvi/XDvi ${WRKSRC}/texmf/xdvi
	env TEXMFCONFIG=${LOCALBASE}/share/texmf \
		TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		${LOCALBASE}/bin/texconfig xdvi paper ${XDVI_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/xdvi/XDvi \
		${DESTDIR}${PREFIX}/share/examples/xdvik

.include "../../mk/bsd.pkg.mk"
