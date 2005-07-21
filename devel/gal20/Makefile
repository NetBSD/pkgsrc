# $NetBSD: Makefile,v 1.7 2005/07/21 16:29:46 wiz Exp $
#

DISTNAME=	gal-1.99.11
PKGNAME=	${DISTNAME:S/gal/gal20/}
PKGREVISION=	2
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gal/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rh@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library functions that came from Gnumeric and Evolution

USE_TOOLS+=		gmake
USE_PKGLOCALEDIR=	yes
BUILD_USES_MSGFMT=	yes
USE_LIBTOOL=		yes
PKGCONFIG_OVERRIDE+=	gal-2.0.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/pkg-config/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
.include "../../textproc/intltool/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
