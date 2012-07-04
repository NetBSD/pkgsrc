# $NetBSD: Makefile,v 1.14 2012/07/04 20:31:56 drochner Exp $

DISTNAME=	luatex-beta-0.70.1
PKGNAME=	${DISTNAME:S/-beta//:S/-source//}
PKGREVISION=	2
CATEGORIES=	print
MASTER_SITES=	http://foundry.supelec.fr/gf/download/frsrelease/392/1730/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	http://www.luatex.org/
COMMENT=	Extended version of pdfTeX using Lua
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir
MAKE_JOBS_SAFE=no

CONFLICTS+=	web2c<=7.5.7nb3
DEPENDS+=	kpathsea>=6.0.1:../../print/kpathsea

GNU_CONFIGURE=	yes
USE_LANGUAGES=	c c++
USE_LIBTOOL=	yes
USE_TOOLS+=	gmake pkg-config
WRKSRC=		${WRKDIR}/${DISTNAME:S/-source//}/source

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
		--enable-luatex \
		--disable-makeindexk \
		--disable-mf  \
		--disable-mmafm \
		--disable-mmpfb \
		--enable-mp \
		--disable-musixflx \
		--disable-otfinfo \
		--disable-otftotfm  \
		--disable-pdfopen  \
		--disable-pdftex  \
		--disable-ptex \
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
		--with-system-freetype2 \
		--without-system-gd \
		--without-system-teckit \
		--without-system-t1lib \
		--without-x \
		--disable-native-texlive-build \
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
CONFIGURE_ARGS+=--with-system-zziplib \
		--with-zziplib-include=${BUILDLINK_PREFIX.zziplib}/include \
		--with-zziplib-libdir=${BUILDLINK_PREFIX.zziplib}/lib
CONFIGURE_ARGS+=--with-system-poppler \
		--with-poppler-include=${BUILDLINK_PREFIX.poppler}/include \
		--with-poppler-libdir=${BUILDLINK_PREFIX.poppler}/lib
CONFIGURE_DIRS+=. texk/web2c
MAKE_FLAGS+=	LIBTOOL=${LIBTOOL:Q}
CFLAGS+=	-DLUA_ROOT=\"${PREFIX}/\"

INSTALLATION_DIRS+=	bin

.include "../../archivers/zziplib/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"

post-extract:
	${RM} -rf ${WRKSRC}/texk/kpathsea
	${ECHO} '#define luatex_svn_revision 4279' \
		> ${WRKSRC}/texk/web2c/luatexdir/luatex_svnversion.h

do-install:
.for f in luatex
	${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/${f} ${DESTDIR}${PREFIX}/bin
.endfor
.for f in texlua texluac
	${LN} -s luatex ${DESTDIR}${PREFIX}/bin/${f}
.endfor

.include "../../mk/bsd.pkg.mk"
