# $NetBSD: Makefile,v 1.58 2024/03/21 08:17:35 markd Exp $

.include "../../print/texlive/Makefile.common"

PKGNAME=	dvipdfmx-20240305
CATEGORIES=	print converters

HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	DVI to PDF converter with CID-keyed font support
LICENSE=	gnu-gpl-v2

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*
CONFLICTS+=	xdvipdfm-[0-9]*
DEPENDS+=	tex-dvipdfmx-[0-9]*:../../print/tex-dvipdfmx
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex
DEPENDS+=	tex-texlive-scripts-[0-9]*:../../print/tex-texlive-scripts

EXTRACT_ELEMENTS+=	${DISTNAME}/texk/dvipdfm-x

WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvipdfm-x

CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-libpaper
CONFIGURE_ARGS+=	--with-libpaper-includes=${BUILDLINK_PREFIX.libpaper}/include
CONFIGURE_ARGS+=	--with-libpaper-libdir=${BUILDLINK_PREFIX.libpaper}/lib

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dvipdfmx
CONF_FILES=	${PREFIX}/share/texmf-dist/dvipdfmx/dvipdfmx.cfg \
		${PKG_SYSCONFDIR}/dvipdfmx/dvipdfmx.cfg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	data/dvipdfmx.cfg dvipdft
SUBST_SED.paths=	-e 's,@DVIPDFM@,${PREFIX}/bin/dvipdfm,g'
SUBST_SED.paths+=	-e 's,@RUNGS@,${PREFIX}/bin/rungs,'

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
