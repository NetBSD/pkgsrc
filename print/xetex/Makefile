# $NetBSD: Makefile,v 1.105 2020/11/05 09:09:00 ryoon Exp $

PKGREVISION= 4
.include "../../print/texlive/Makefile.common"

PKGNAME=	xetex-0.999992
CATEGORIES=	print

HOMEPAGE=	https://www.tug.org/xetex/
COMMENT=	TeX system with Unicode and modern font technologies
LICENSE=	mit

CONFLICTS+=	web2c<=7.5.7
DEPENDS+=	dvipdfmx>=20140525:../../print/dvipdfmx

EXTRACT_ELEMENTS+=	${DISTNAME}/libs/xpdf
EXTRACT_ELEMENTS+=	${DISTNAME}/texk/web2c

USE_LANGUAGES=		c99 c++11
USE_TOOLS+=		gmake lex perl yacc
GNU_CONFIGURE_STRICT=	no # libs
CONFIGURE_ARGS+=	--disable-aleph
CONFIGURE_ARGS+=	--disable-eptex
CONFIGURE_ARGS+=	--disable-euptex
CONFIGURE_ARGS+=	--disable-etex
CONFIGURE_ARGS+=	--disable-luajittex
CONFIGURE_ARGS+=	--disable-luajithbtex
CONFIGURE_ARGS+=	--disable-luahbtex
CONFIGURE_ARGS+=	--disable-luatex
CONFIGURE_ARGS+=	--disable-luatex53
CONFIGURE_ARGS+=	--disable-mf
CONFIGURE_ARGS+=	--disable-mf-nowin
CONFIGURE_ARGS+=	--disable-mflua
CONFIGURE_ARGS+=	--disable-mfluajit
CONFIGURE_ARGS+=	--disable-mp
CONFIGURE_ARGS+=	--disable-pdftex
CONFIGURE_ARGS+=	--disable-pmp
CONFIGURE_ARGS+=	--disable-ptex
CONFIGURE_ARGS+=	--disable-uptex
CONFIGURE_ARGS+=	--disable-upmp
CONFIGURE_ARGS+=	--disable-web-progs
CONFIGURE_ARGS+=	--enable-web2c
CONFIGURE_ARGS+=	--enable-xetex
CONFIGURE_ARGS+=	--with-fontconfig-includes=${BUILDLINK_PREFIX.fontconfig}/include
CONFIGURE_ARGS+=	--with-fontconfig-libdir=${BUILDLINK_PREFIX.fontconfig}/lib
CONFIGURE_ARGS+=	--with-system-graphite2
CONFIGURE_ARGS+=	--with-system-harfbuzz
CONFIGURE_ARGS+=	--with-system-kpathsea
CONFIGURE_ARGS+=	--with-system-poppler
CONFIGURE_ARGS+=	--with-system-zlib
CONFIGURE_ARGS+=	--with-zlib-includes=${BUILDLINK_PREFIX.zlib}/include
CONFIGURE_ARGS+=	--with-zlib-libdir=${BUILDLINK_PREFIX.zlib}/lib
CONFIGURE_ARGS+=	--with-system-libpng
CONFIGURE_ARGS+=	--with-system-freetype2
CONFIGURE_ARGS+=	--with-system-teckit
CONFIGURE_ARGS+=	--with-system-icu
CONFIGURE_ARGS+=	--without-x

CONFIGURE_DIRS+=	libs/xpdf
CONFIGURE_DIRS+=	texk/web2c

SUBST_CLASSES+=		paths
SUBST_MESSAGE.paths=	Setting paths to commands.
SUBST_STAGE.paths=	pre-configure
SUBST_FILES.paths=	texk/web2c/xetexdir/XeTeX_ext.c
SUBST_SED.paths=	-e 's,@XDVIPDFMX@,${PREFIX}/bin/xdvipdfmx,g'

INSTALLATION_DIRS+=	bin

CFLAGS.SunOS+=		-D_XOPEN_SOURCE_EXTENDED=0

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/texk/web2c/xetex ${DESTDIR}${PREFIX}/bin

.include "../../converters/TECkit/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../fonts/harfbuzz/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../graphics/graphite2/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
BUILDLINK_API_DEPENDS.kpathsea+= kpathsea>=6.2.1
.include "../../print/kpathsea/buildlink3.mk"
.include "../../print/poppler/buildlink3.mk"
.include "../../print/poppler-includes/buildlink3.mk"
.include "../../textproc/icu/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
