# $NetBSD: Makefile,v 1.38 2006/01/24 07:32:16 wiz Exp $
#

DISTNAME=		libgnomecanvas-2.12.0
PKGREVISION=		1
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomecanvas/2.12/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.gnome.org/
COMMENT=		GNOME Canvas library

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_PKGLOCALEDIR=	yes
USE_TOOLS+=		gmake pkg-config
USE_LIBTOOL=		yes

PKGCONFIG_OVERRIDE=	libgnomecanvas/libgnomecanvas-2.0.pc.in

CONFIGURE_ARGS+=	--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc

.include "../../devel/gettext-lib/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
