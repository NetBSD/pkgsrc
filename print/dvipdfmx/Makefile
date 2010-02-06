# $NetBSD: Makefile,v 1.34 2010/02/06 00:59:50 minskim Exp $

DISTNAME=	texlive-20091011-source
PKGNAME=	dvipdfmx-20090708
PKGREVISION=	1
CATEGORIES=	print converters
MASTER_SITES=	${MASTER_SITE_TEX_CTAN:=systems/texlive/Source/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://project.ktug.or.kr/dvipdfmx/
COMMENT=	DVI to PDF converter with CID-keyed font support

CONFLICTS+=	dvipdfm-[0-9]*
CONFLICTS+=	ja-dvipdfm-[0-9]*
DEPENDS+=	tex-dvipdfmx-[0-9]*:../../print/tex-dvipdfmx
DEPENDS+=	tex-pdftex-[0-9]*:../../print/tex-pdftex

EXTRACT_ELEMENTS=	${DISTNAME}/build-aux \
			${DISTNAME}/texk/dvipdfmx

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gs:run ps2pdf:run
WRKSRC=		${WRKDIR}/${DISTNAME}/texk/dvipdfmx

CONFIGURE_ARGS+=	--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=	--with-system-zlib \
		--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng \
		--with-libpng-includes=${BUILDLINK_PREFIX.png}/include \
		--with-libpng-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=	--with-paper=${BUILDLINK_PREFIX.libpaper}

PKG_SYSCONFSUBDIR=	texmf

MAKE_DIRS+=	${PKG_SYSCONFDIR}/dvipdfmx
CONF_FILES=	${PREFIX}/share/texmf/dvipdfmx/dvipdfmx.cfg \
		${PKG_SYSCONFDIR}/dvipdfmx/dvipdfmx.cfg

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	data/dvipdfmx.cfg src/dvipdft
SUBST_SED.paths=	-e 's,@DVIPDFM@,${PREFIX}/bin/dvipdfm,g' \
			-e 's,@GS@,${TOOLS_PATH.gs},g' \
			-e 's,@PS2PDF@,${LOCALBASE}/bin/ps2pdf,g'

TEX_TEXMF_DIRS+=	${PKG_SYSCONFDIR}
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf
TEX_TEXMF_DIRS+=	${PREFIX}/share/texmf-dist

.include "../../graphics/png/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/kpathsea/texmf.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
