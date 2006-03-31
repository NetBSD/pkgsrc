# $NetBSD: Makefile,v 1.47 2006/03/31 09:08:08 jmmv Exp $
#

DISTNAME=	librsvg-2.14.2
PKGNAME=	${DISTNAME:S/-/2-/}
PKGREVISION=	2
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/librsvg/2.14/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	jmmv@NetBSD.org
HOMEPAGE=	http://librsvg.sourceforge.net/
COMMENT=	SVG library for GNOME2

CONFLICTS+=	librsvg2-gtk-[0-9]*

USE_DIRS+=		xdg-1.1
USE_LIBTOOL=		yes
USE_TOOLS+=		pkg-config
GNU_CONFIGURE=		yes

PKGCONFIG_OVERRIDE=	librsvg-2.0.pc.in

CONFIGURE_ARGS+=	--disable-gtk-doc
CONFIGURE_ARGS+=	--with-gimp=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/librsvg2
CONFIGURE_ARGS+=	--with-tags=

CFLAGS.Darwin+=		-flat_namespace -undefined suppress
LDFLAGS.Darwin+=	-lfreetype -lfontconfig

GTK2_LOADERS=		yes

.include "../../devel/libgsf/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
BUILDLINK_DEPENDS.libcroco+=	libcroco>=0.6.1
.include "../../textproc/libcroco/buildlink3.mk"
.include "../../x11/gtk2/modules.mk"
.include "../../mk/bsd.pkg.mk"
