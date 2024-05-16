# $NetBSD: Makefile,v 1.228 2024/05/16 06:14:48 wiz Exp $

PKGREVISION= 	19
.include 	"Makefile.common"

DISTNAME=	abiword-${ABIVERSION}
CATEGORIES=	editors
MASTER_SITES=	http://www.nl.abisource.com/downloads/abiword/${PKGVERSION_NOREV}/source/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.abisource.com/
COMMENT=	Open Source cross-platform word processor
LICENSE=	gnu-gpl-v2

CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

DEPENDS+=	adwaita-icon-theme>0:../../graphics/adwaita-icon-theme
TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config

CONFIGURE_ARGS+=	--disable-default-plugins	# Do not build any plugins by default
CONFIGURE_ARGS+=	--enable-spell         # (Gtk+ only) include spell checking support
CONFIGURE_ARGS+=	--enable-plugins=""
# evolution data server can't be found even if buildlinked
# disable to make sure it's not found somewhere else
CONFIGURE_ARGS+=	--with-evolution-data-server=no

PKGCONFIG_OVERRIDE+=	libabiword.pc.in

pre-configure:
	cd ${WRKSRC}; \
	autoreconf --force --install

.include "../../mk/bsd.prefs.mk"

.if ${OPSYS} != "Darwin"
BUILDLINK_TRANSFORM+=	opt:-no-undefined:-Wl,--no-undefined
.endif

.include "options.mk"

.include "../../converters/fribidi/buildlink3.mk"
.include "../../converters/wv/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../textproc/enchant2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../textproc/redland/buildlink3.mk"
.include "../../time/libical/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
