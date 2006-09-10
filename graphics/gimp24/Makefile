# $NetBSD: Makefile,v 1.26 2006/09/10 22:59:16 adam Exp $

DISTNAME=	gimp-2.3.11
CATEGORIES=	graphics
MASTER_SITES=	ftp://ftp.gimp.org/pub/gimp/v2.3/ \
		ftp://ftp.cs.umn.edu/pub/gimp/v2.3/ \
		ftp://ftp.sunet.se/pub/gnu/gimp/v2.3/ \
		ftp://ftp.gwdg.de/pub/misc/grafik/gimp/gimp/v2.3/ \
		ftp://ftp.minet.net/pub/gimp/v2.3/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	adam@NetBSD.org
HOMEPAGE=	http://www.gimp.org/
COMMENT=	Image manipulation program similar to Photoshop[tm]

CONFLICTS+=		gimp<=1.2.3

USE_LIBTOOL=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake intltool msgfmt pkg-config

PKG_SYSCONFSUBDIR=	gimp/2.0

PKGCONFIG_OVERRIDE=	gimp-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gimpthumb-2.0.pc.in
PKGCONFIG_OVERRIDE+=	gimpui-2.0.pc.in

.include "../../mk/bsd.prefs.mk"

USE_BUILTIN.fontconfig=			no
BUILDLINK_API_DEPENDS.fontconfig+=	fontconfig>=2.2.0
BUILDLINK_API_DEPENDS.lcms+=		lcms>=1.12

GNU_CONFIGURE=		yes
CONFIGURE_ARGS+=	--disable-perl
CONFIGURE_ARGS+=	--disable-python
CONFIGURE_ARGS+=	--sysconfdir=${PKG_SYSCONFDIR:Q}
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/${PKGNAME_NOREV}
CONFIGURE_ARGS+=	--with-gimpprint-prefix=${BUILDLINK_PREFIX.gimp-print-lib}

UNLIMIT_RESOURCES+=	datasize

EGDIR=			${PREFIX}/share/examples/gimp-2.0
.for f in controllerrc gimprc gtkrc ps-menurc sessionrc templaterc unitrc
CONF_FILES+=		${EGDIR}/${f} ${PKG_SYSCONFDIR}/${f}
.endfor

# Ensure we export symbols in the linked shared object.
LDFLAGS+=		${EXPORT_SYMBOLS_LDFLAGS}

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../fonts/fontconfig/buildlink3.mk"
.include "../../graphics/aalib/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/lcms/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../graphics/libexif/buildlink3.mk"
.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/mng/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/tiff/buildlink3.mk"
.include "../../graphics/libwmf/buildlink3.mk"
.include "../../print/gimp-print-lib/buildlink3.mk"
.include "../../www/libgtkhtml/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"

.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
