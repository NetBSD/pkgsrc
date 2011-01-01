# $NetBSD: Makefile,v 1.28 2011/01/01 13:19:37 obache Exp $

DISTNAME=	mkvtoolnix-4.3.0
PKGREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://www.bunkus.org/videotools/mkvtoolnix/sources/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://www.bunkus.org/videotools/mkvtoolnix/
COMMENT=	Set of tools to create, alter and inspect Matroska files
LICENSE=	gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake msgfmt
USE_PKGLOCALEDIR=	yes
USE_LANGUAGES=	c c++

CONFIGURE_ARGS+=	--with-boost-libdir=${BUILDLINK_PREFIX.boost-libs}
CONFIGURE_ARGS+=	--with-boost_regex=boost_regex
CONFIGURE_ARGS+=	--with-boost-filesystem=boost_filesystem

PKG_OPTIONS_VAR=	PKG_OPTIONS.mkvtoolnix
PKG_SUPPORTED_OPTIONS=	mkvtoolnix-gui
PKG_SUGGESTED_OPTIONS=

.include "../../mk/bsd.options.mk"

PLIST_VARS+=	gui

.if !empty(PKG_OPTIONS:Mmkvtoolnix-gui)
PLIST.gui=	yes
CONFIGURE_ARGS+=	--enable-gui
CONFIGURE_ARGS+=	--enable-wxwidgets
.   include "../../x11/wxGTK28/buildlink3.mk"
.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.else
CONFIGURE_ARGS+=	--disable-gui
CONFIGURE_ARGS+=	--disable-wxwidgets
.endif

do-build:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ruby drake

do-install:
	cd ${WRKSRC} && ${SETENV} ${INSTALL_ENV} ruby drake install

BUILDLINK_DEPMETHOD.${RUBY_BASE}=	build
.include "../../lang/ruby/buildlink3.mk"

.include "../../archivers/bzip2/buildlink3.mk"
.include "../../archivers/liblzo/buildlink3.mk"
.include "../../audio/flac/buildlink3.mk"
.include "../../audio/libvorbis/buildlink3.mk"
.include "../../converters/libiconv/buildlink3.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libebml/buildlink3.mk"
.include "../../devel/zlib/buildlink3.mk"
.include "../../devel/boost-headers/buildlink3.mk"
.include "../../devel/boost-libs/buildlink3.mk"
.include "../../multimedia/libmatroska/buildlink3.mk"
.include "../../multimedia/libogg/buildlink3.mk"
.include "../../sysutils/file/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"

.include "../../mk/bsd.pkg.mk"
