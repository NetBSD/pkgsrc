# $NetBSD: Makefile,v 1.124 2024/12/27 08:20:03 wiz Exp $

DISTNAME=	tuxpaint-0.9.34
PKGREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:=tuxpaint/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.tuxpaint.org/
COMMENT=	Drawing program for small children
# program itself is gnu-gpl-v2, other licenses are packaged fonts
LICENSE=	gnu-gpl-v2 AND gnu-lgpl-v2.1 AND public-domain AND modified-bsd

TOOL_DEPENDS+=	gperf-[0-9]*:../../devel/gperf
# composite
TOOL_DEPENDS+=	ImageMagick-[0-9]*:../../graphics/ImageMagick

USE_TOOLS+=		bash:run gmake gsed msgfmt pkg-config

CONFLICTS+=		tuxpaint-stamps<2003.12.23

REPLACE_BASH=		src/tuxpaint-import.sh

PKG_SYSCONFSUBDIR=	tuxpaint
MAKE_FLAGS+=		CONFDIR=${PKG_SYSCONFDIR}
MAKE_FLAGS+=		PREFIX=${PREFIX}
MAKE_FLAGS+=		LOCALE_PREFIX=${DESTDIR}${PREFIX}/${PKGLOCALEDIR}/locale
MAKE_FLAGS+=		MAN_PREFIX=${DESTDIR}${PREFIX}/${PKGMANDIR}/
MAKE_FLAGS+=		GPERF=${PREFIX}/bin/gperf
# autodetection of libpaper fails
MAKE_FLAGS+=		PAPER_LIB=-lpaper
EGDIR=			${PREFIX}/share/examples/tuxpaint
CONF_FILES=		${EGDIR}/tuxpaint.conf ${PKG_SYSCONFDIR}/tuxpaint.conf

INSTALL_MAKE_FLAGS+=	CONFDIR=${DESTDIR}${PREFIX}/share/examples/tuxpaint

# src/tuxpaint.c:233:2: warning: #warning "Attempting to define strcasestr(); if errors, build with -DHAVE_STRCASESTR" [-Wcpp]
MAKE_FLAGS.NetBSD+=		linux_ARCH_CFLAGS=-DHAVE_STRCASESTR

# TODO: still needed?
LIBS.SunOS+=		-lsocket -lnsl
LDFLAGS.SunOS+=		-lsocket

# python2, fontforge - will not realistically be run by users
CHECK_INTERPRETER_SKIP+=	share/tuxpaint/fonts/locale/zh_tw_docs/maketuxfont.py
CHECK_INTERPRETER_SKIP+=	share/tuxpaint/fonts/locale/zh_tw_docs/tuxpaintsubset.pe

.include "../../audio/SDL2_mixer/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../converters/fribidi/buildlink3.mk"
.include "../../devel/SDL2/buildlink3.mk"
.include "../../devel/SDL2_Pango/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../fonts/SDL2_ttf/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../graphics/SDL2_gfx/buildlink3.mk"
.include "../../graphics/SDL2_image/buildlink3.mk"
.include "../../graphics/libimagequant/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/cairo/buildlink3.mk"
.include "../../print/libpaper/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
