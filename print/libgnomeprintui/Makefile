# $NetBSD: Makefile,v 1.15 2003/12/13 00:45:25 wiz Exp $
#

DISTNAME=		libgnomeprintui-2.2.1.2
PKGREVISION=		5
CATEGORIES=		print gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/libgnomeprintui/2.2/}
EXTRACT_SUFX=		.tar.bz2

MAINTAINER=		jmmv@NetBSD.org
HOMEPAGE=		http://www.levien.com/gnome/print-arch.html
COMMENT=		Graphical library for the GNOME2 Printing Architecture

BUILD_USES_MSGFMT=	yes

GNU_CONFIGURE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
USE_GMAKE=		yes
USE_X11=		yes
USE_LIBTOOL=		yes

LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE=	${WRKSRC}/libgnomeprintui/libgnomeprintui-2.2.pc.in

CONFIGURE_ARGS=		--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/gettext-lib/buildlink2.mk"
.include "../../devel/GConf2/buildlink2.mk"
.include "../../devel/bonobo-activation/buildlink2.mk"
.include "../../devel/libbonobo/buildlink2.mk"
.include "../../devel/libglade2/buildlink2.mk"
.include "../../devel/zlib/buildlink2.mk"
.include "../../graphics/libart2/buildlink2.mk"
.include "../../graphics/libgnomecanvas/buildlink2.mk"
.include "../../print/libgnomeprint/buildlink2.mk"
.include "../../textproc/libxml2/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
