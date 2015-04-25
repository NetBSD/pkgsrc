# $NetBSD: Makefile,v 1.45 2015/04/25 13:07:05 markd Exp $

DISTNAME=	texlive-20140525-source
PKGNAME=	dvipdfmx-20140525
CATEGORIES=	print converters
MASTER_SITES=	ftp://tug.org/historic/systems/texlive/2014/
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	DVI to PDF converter with CID-keyed font support

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*
DEPENDS+=	tex-dvipdfmx-[0-9]*:../../print/tex-dvipdfmx
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/dvipdfm-x

GNU_CONFIGURE=	yes
USE_TOOLS+=	pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvipdfm-x

CONFIG_GUESS_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.guess
CONFIG_SUB_OVERRIDE+=	${WRKDIR}/${DISTNAME}/build-aux/config.sub

CONFIGURE_ARGS+=	--with-system-freetype2 \
		--with-freetype2-includes=${BUILDLINK_PREFIX.freetype2}/include/freetype2 \
		--with-freetype2-libdir=${BUILDLINK_PREFIX.freetype2}/lib
CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
		--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-libpaper \
		--with-libpaper-includes=${BUILDLINK_PREFIX.libpaper}/include \
		--with-libpaper-libdir=${BUILDLINK_PREFIX.libpaper}/lib

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dvipdfmx
CONF_FILES=	${PREFIX}/share/texmf-dist/dvipdfmx/dvipdfmx.cfg \
		${PKG_SYSCONFDIR}/dvipdfmx/dvipdfmx.cfg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	data/dvipdfmx.cfg src/dvipdft
SUBST_SED.paths=	-e 's,@DVIPDFM@,${PREFIX}/bin/dvipdfm,g'
SUBST_SED.paths+=	-e 's,@RUNGS@,${LOCALBASE}/bin/rungs,g'

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
