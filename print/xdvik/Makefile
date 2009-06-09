# $NetBSD: Makefile,v 1.4 2009/06/09 21:31:04 minskim Exp $

DISTNAME=	xdvik-22.84.14
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=xdvi/}

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://xdvi.sourceforge.net/
COMMENT=	Previewer for DVI files

CONFLICTS+=	teTeX-bin<3.0nb25
BUILD_DEPENDS+=	texlive-tetex-[0-9]*:../../print/texlive-tetex
BUILD_DEPENDS+=	tex-bin-xdvi-[0-9]*:../../print/tex-bin-xdvi

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/xdvik

FIND_PREFIX:=	TETEX_PREFIX=texlive-tetex BIN_XDVI_PREFIX=tex-bin-xdvi
.include "../../mk/find-prefix.mk"

CONFIGURE_ARGS+=	--with-system-kpathsea --with-system-t1lib \
			--with-xdvi-x-toolkit=xaw

MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q} \
		kpathsea_parent=${BUILDLINK_PREFIX.kpathsea}/include

INSTALL_MAKE_FLAGS+=	prefix=${DESTDIR}${PREFIX} \
			mandir=${DESTDIR}${PREFIX}/${PKGMANDIR}

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/xdvi
CONF_FILES=	${PREFIX}/share/texmf-dist/xdvi/XDvi \
		${PKG_SYSCONFDIR}/xdvi/XDvi

BUILD_DEFS+=	PAPERSIZE

INSTALLATION_DIRS+=	share/texmf-dist/xdvi

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../mk/bsd.prefs.mk"

.if ${PAPERSIZE} == "Letter"
XDVI_PAPERSIZE=	us
.else
XDVI_PAPERSIZE=	a4
.endif

.include "../../converters/libiconv/buildlink3.mk"
.include "../../fonts/t1lib/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../x11/libXp/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/xaw.buildlink3.mk"

post-build:
	${MKDIR} -p ${WRKSRC}/texmf/xdvi
	${CP} ${BIN_XDVI_PREFIX}/share/texmf/xdvi/XDvi \
		${WRKSRC}/texmf/xdvi
	env TEXMFCONFIG=${BIN_XDVI_PREFIX}/share/texmf \
		TFC_TEXMFCONFIG=${WRKSRC}/texmf \
		${TETEX_PREFIX}/bin/texconfig xdvi paper ${XDVI_PAPERSIZE}

post-install:
	${INSTALL_DATA} ${WRKSRC}/texmf/xdvi/XDvi \
		${DESTDIR}${PREFIX}/share/texmf-dist/xdvi

.include "../../mk/bsd.pkg.mk"
