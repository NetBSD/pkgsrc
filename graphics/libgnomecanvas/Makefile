# $NetBSD: Makefile,v 1.35 2005/07/21 16:29:51 wiz Exp $
#

DISTNAME=		libgnomecanvas-2.10.2
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomecanvas/2.10/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Canvas library

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libgnomecanvas/libgnomecanvas-2.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
