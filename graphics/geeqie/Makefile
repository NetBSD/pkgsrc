# $NetBSD: Makefile,v 1.130 2024/05/29 16:32:51 adam Exp $

DISTNAME=	geeqie-2.4
PKGREVISION=	4
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
DEPENDS+=	webp-pixbuf-loader-[0-9]*:../../graphics/webp-pixbuf-loader

LDFLAGS.SunOS+=		-lm -lsocket -lnsl

MESON_ARGS+=	-Ddoxygen=disabled
MESON_ARGS+=	-Dpandoc=disabled
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

MESON_ARGS+=	-Dgq_localedir='${PREFIX}/${PKGLOCALEDIR}/locale'
MESON_ARGS+=	--localedir='${PKGLOCALEDIR}/locale'

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
.include "../../graphics/openjpeg/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
