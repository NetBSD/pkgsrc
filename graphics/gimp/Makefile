# $NetBSD: Makefile,v 1.220 2012/09/15 10:04:52 obache Exp $

DISTNAME=	gimp-2.8.2
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v${PKGVERSION_NOREV:R}/ \
		${MASTER_SITE_GNU:=gimp/v${PKGVERSION_NOREV:R}/} \
		ftp://ftp.gwdg.de/pub/misc/grafik/gimp/gimp/v${PKGVERSION_NOREV:R}/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	The GNU image manipulation program
LICENSE=	gnu-lgpl-v2.1 AND gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=	p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser
CONFLICTS+=	gimp<=1.2.3

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--without-linux-input
CONFIGURE_ARGS+=	--without-mac-twain

PKG_SYSCONFSUBDIR=	gimp/2.0
PKGCONFIG_OVERRIDE=	gimp.pc.in
UNLIMIT_RESOURCES+=	datasize

.include "../../mk/bsd.prefs.mk"

EGDIR=			${PREFIX}/share/examples/gimp-2.0
.for f in controllerrc gimprc gtkrc menurc sessionrc templaterc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

PLIST_VARS+=		remote

BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2.0
BUILDLINK_API_DEPENDS.lcms+=		lcms>=1.12

.include "options.mk"

.include "../../sysutils/desktop-file-utils/desktopdb.mk"
.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/babl/buildlink3.mk"
.include "../../graphics/gegl/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if !empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
PLIST.remote=	yes
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.include "../../x11/libXpm/buildlink3.mk"
.endif
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
