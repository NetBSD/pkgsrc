# $NetBSD: Makefile,v 1.24 2004/01/24 02:00:26 jlam Exp $
#

DISTNAME=	fontconfig-2.2.1
PKGREVISION=	3
CATEGORIES=	fonts gnome
MASTER_SITES=	http://pdx.freedesktop.org/software/fontconfig/releases/

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://fontconfig.org/
COMMENT=	Library for configuring and customizing font access

# This can use 2.0.5 but things which use it (ala pango) require 2.0.9 so make
# sure to keep in step
BUILDLINK_DEPENDS.freetype2+=	freetype2>=2.0.9

.include "../../mk/bsd.prefs.mk"

GNU_CONFIGURE=		YES
USE_BUILDLINK3=		YES
USE_LIBTOOL=		YES
USE_PKGINSTALL=		YES
USE_GNU_TOOLS+=		make

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/fontconfig.pc.in

PKG_SYSCONFSUBDIR=	fontconfig

CONFIGURE_ARGS+=	--with-default-fonts=${LOCALBASE}/lib/X11/fonts
CONFIGURE_ARGS+=	--with-freetype-includes=${BUILDLINK_PREFIX.freetype2}/include/freetype2
CONFIGURE_ARGS+=	--with-freetype-lib=${BUILDLINK_PREFIX.freetype2}/lib
CONFIGURE_ARGS+=	--with-expat-includes=${BUILDLINK_PREFIX.expat}/include
CONFIGURE_ARGS+=	--with-expat-lib=${BUILDLINK_PREFIX.expat}/lib
CONFIGURE_ARGS+=	--with-confdir=${PKG_SYSCONFDIR}
CONFIGURE_ARGS+=	--with-x

FONT_PATH=	${X11PREFIX}/lib/X11/fonts/TTF,${X11PREFIX}/lib/X11/fonts/Type1
.if ${X11PREFIX} != ${X11BASE}
FONT_PATH2=	,${X11BASE}/lib/X11/fonts,${X11BASE}/lib/X11/fonts/TTF,${X11BASE}/lib/X11/fonts/Type1
.endif
CONFIGURE_ARGS+=	--with-add-fonts=${FONT_PATH}${FONT_PATH2}

EGDIR=		${PREFIX}/share/examples/fontconfig
CONF_FILES=	${EGDIR}/fonts.conf ${PKG_SYSCONFDIR}/fonts.conf
CONF_FILES+=	${EGDIR}/fonts.dtd ${PKG_SYSCONFDIR}/fonts.dtd
CONF_FILES+=	${EGDIR}/local.conf ${PKG_SYSCONFDIR}/local.conf

.include "../../devel/zlib/buildlink3.mk"
.include "../../graphics/freetype2/buildlink3.mk"
.include "../../textproc/expat/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
