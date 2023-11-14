# $NetBSD: Makefile,v 1.119 2023/11/14 14:02:01 wiz Exp $

DISTNAME=	geeqie-2.1
PKGREVISION=	5
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=BestImageViewer/}
EXTRACT_SUFX=	.tar.xz
GITHUB_RELEASE=	v${PKGVERSION_NOREV}

MAINTAINER=	gdt@NetBSD.org
HOMEPAGE=	http://www.geeqie.org/
COMMENT=	Image viewer
LICENSE=	gnu-gpl-v2

TOOL_DEPENDS+=	gettext-m4-[0-9]*:../../devel/gettext-m4
# .../geeqie-2.0.1/scripts/generate-ClayRGB1998-icc-h.sh: xxd: not found
TOOL_DEPENDS+=	vim-share-[0-9]*:../../editors/vim-share

LDFLAGS.SunOS+=		-lm -lsocket -lnsl

MESON_ARGS+=	-Ddoxygen=disabled
# Do not build html documentation.
# \todo Consider depending on yelp instead
MESON_ARGS+=	-Dyelp-build=disabled

USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=		c c++
USE_TOOLS=		bash:run msgfmt pkg-config

REPLACE_BASH+=		plugins/*/*
REPLACE_BASH+=		doc/*.sh
REPLACE_BASH+=		g*.sh
REPLACE_BASH+=		version.sh

INSTALLATION_DIRS=	${PKGMANDIR}/man1

.include "../../mk/bsd.fast.prefs.mk"

post-install:
.if ${PKGMANDIR} != "share/man"
	${MV} ${DESTDIR}${PREFIX}/share/man/man1/*.1 ${DESTDIR}${PREFIX}/${PKGMANDIR}/man1
.endif

.include "options.mk"

.include "../../devel/meson/build.mk"
.include "../../graphics/exiv2/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/lcms2/buildlink3.mk"
.include "../../graphics/libheif/buildlink3.mk"
.include "../../graphics/libwebp/buildlink3.mk"
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
