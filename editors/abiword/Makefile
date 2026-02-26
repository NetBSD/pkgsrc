# $NetBSD: Makefile,v 1.249 2026/02/26 02:06:52 gutteridge Exp $

.include 	"Makefile.common"

PKGNAME=	${DISTNAME:tl:S/-release//1}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/World/AbiWord
COMMENT=	Open Source cross-platform word processor
LICENSE=	gnu-gpl-v2

CONFLICTS=	abiword-personal-[0-9]* abiword2-[0-9]*

DEPENDS+=	adwaita-icon-theme>0:../../graphics/adwaita-icon-theme
TOOL_DEPENDS+=	autoconf-archive-[0-9]*:../../devel/autoconf-archive

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	autoconf automake gmake pkg-config perl

REPLACE_PERL+=	tools/cdump/xp/cdump.pl
REPLACE_PERL+=	po/*.pl

CONFIGURE_ARGS+=	--disable-default-plugins	# Do not build any plugins by default
CONFIGURE_ARGS+=	--enable-spell         # (Gtk+ only) include spell checking support
CONFIGURE_ARGS+=	--enable-plugins=""
# evolution data server can't be found even if buildlinked
# disable to make sure it's not found somewhere else
CONFIGURE_ARGS+=	--with-evolution-data-server=no

PKGCONFIG_OVERRIDE+=	libabiword.pc.in

.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc-14.*} || ${CC_VERSION:Mgcc-15.*}
CFLAGS+=	-Wno-incompatible-pointer-types
.endif

pre-configure:
	cd ${WRKSRC} && ${ALL_ENV} ${SH} autogen.sh

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
