# $NetBSD: Makefile,v 1.2 2009/06/10 02:01:02 minskim Exp $

DISTNAME=	luatex-beta-0.40.2
PKGNAME=	${DISTNAME:S/-beta//}
CATEGORIES=	print
MASTER_SITES=	http://foundry.supelec.fr/gf/download/frsrelease/341/1275/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	Extended version of pdfTeX using Lua

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=	web2c<=7.5.7nb3

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_TOOLS+=	gmake
WRKSRC=		${WRKDIR}/${DISTNAME}/source

CONFIGURE_ARGS+=--enable-cxx-runtime-hack \
    --disable-afm2pl    \
    --disable-aleph  \
    --disable-bibtex   \
    --disable-bibtex8   \
    --disable-cfftot1 \
    --disable-cjkutils  \
    --disable-detex    \
    --disable-devnag   \
    --disable-dialog   \
    --disable-dtl      \
    --enable-dump-share  \
    --disable-dvi2tty  \
    --disable-dvidvi   \
    --disable-dviljk   \
    --disable-dvipdfm  \
    --disable-dvipdfmx \
    --disable-dvipos  \
    --disable-dvipsk  \
    --disable-gsftopk \
    --disable-lacheck \
    --disable-lcdf-typetools \
    --disable-makeindexk \
    --disable-mf  \
    --disable-mmafm \
    --disable-mmpfb \
    --disable-musixflx \
    --disable-otfinfo \
    --disable-otftotfm  \
    --disable-pdfopen  \
    --disable-pdftex  \
    --disable-ps2eps   \
    --disable-ps2pkm \
    --disable-psutils  \
    --disable-seetexk \
    --disable-t1dotlessj  \
    --disable-t1lint \
    --disable-t1rawafm \
    --disable-t1reencode \
    --disable-t1testpage \
    --disable-t1utils  \
    --disable-tex    \
    --disable-tex4htk \
    --disable-tpic2pdftex  \
    --disable-ttf2pk \
    --disable-ttfdump \
    --disable-ttftotype42 \
    --disable-vlna  \
    --disable-web-progs \
    --disable-xdv2pdf \
    --disable-xdvipdfmx \
    --disable-xetex \
    --without-system-freetype2 \
    --without-system-gd \
    --without-system-teckit \
    --without-system-t1lib \
    --without-x \
    --disable-shared    \
    --disable-largefile
CONFIGURE_ARGS+=--with-system-kpathsea \
		--with-kpathsea-includes=${BUILDLINK_PREFIX.kpathsea}/include \
		--with-kpathsea-libdir=${BUILDLINK_PREFIX.kpathsea}/lib
CONFIGURE_ARGS+=--with-system-libpng \
		--with-libpng-include=${BUILDLINK_PREFIX.png}/include \
		--with-libpng-libdir=${BUILDLINK_PREFIX.png}/lib
CONFIGURE_ARGS+=--with-system-zlib \
		--with-zlib-include=${BUILDLINK_PREFIX.zlib}/include \
		--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib

INSTALLATION_DIRS+=	bin

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"

post-extract:
	${RM} -rf ${WRKSRC}/texk/kpathsea

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/luatex ${DESTDIR}${PREFIX}/bin
	${LN} -s luatex ${DESTDIR}${PREFIX}/bin/texlua
	${LN} -s luatex ${DESTDIR}${PREFIX}/bin/texluac

.include "../../mk/bsd.pkg.mk"
