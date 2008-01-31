# $NetBSD: Makefile,v 1.172 2008/01/31 20:41:45 adam Exp $

DISTNAME=	gimp-2.4.4
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v2.4/ \
		ftp://ftp.sunet.se/pub/gnu/gimp/v2.4/ \
		ftp://ftp.gwdg.de/pub/misc/grafik/gimp/gimp/v2.4/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	The GNU image manipulation program

BUILD_DEPENDS+=	p5-XML-Parser>=2.31nb1:../../textproc/p5-XML-Parser

PKG_DESTDIR_SUPPORT=	user-destdir

CONFLICTS+=		gimp<=1.2.3

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config
USE_DIRS+=		xdg-1.1

PKG_SYSCONFSUBDIR=	gimp/2.0

PKGCONFIG_OVERRIDE=	gimp.pc.in

.include "../../mk/bsd.prefs.mk"

BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2.0
BUILDLINK_API_DEPENDS.lcms+=		lcms>=1.12

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR}

UNLIMIT_RESOURCES+=	datasize

EGDIR=			${PREFIX}/share/examples/gimp-2.0
.for f in controllerrc gimprc gtkrc menurc ps-menurc sessionrc templaterc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.if exists(/System/Library/Frameworks/TWAIN.framework)
PLIST_SUBST+=	TWAIN=""
.else
PLIST_SUBST+=	TWAIN="@comment "
.endif

.include "options.mk"

.include "../../databases/shared-mime-info/mimedb.mk"
.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.if empty(PKG_BUILD_OPTIONS.gtk2:Mx11)
PLIST_SUBST+=	REMOTE="@comment "
.else
PLIST_SUBST+=	REMOTE=""
.include "../../x11/libICE/buildlink3.mk"
.include "../../x11/libSM/buildlink3.mk"
.include "../../x11/libXmu/buildlink3.mk"
.endif
.include "../../x11/libXpm/buildlink3.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
