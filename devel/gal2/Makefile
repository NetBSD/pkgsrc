# $NetBSD: Makefile,v 1.12 2003/12/06 17:50:02 recht Exp $
#

DISTNAME=	gal-1.99.10
PKGNAME=	${DISTNAME:S/gal/gal2/}
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gal/1.99/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	recht@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Library functions that came from Gnumeric and Evolution

USE_X11=		yes
USE_GMAKE=		yes
USE_BUILDLINK2=		yes
USE_PKGLOCALEDIR=	yes
BUILD_USES_MSGFMT=	yes
USE_LIBTOOL=		yes
LIBTOOL_OVERRIDE=	${WRKSRC}/libtool
PKGCONFIG_OVERRIDE+=	${WRKSRC}/gal-2.0.pc.in
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--enable-gtk-doc=no
CONFIGURE_ARGS+=	--with-html-dir=${PREFIX}/share/doc/html

.include "../../devel/libgnomeui/buildlink2.mk"
.include "../../print/libgnomeprintui/buildlink2.mk"
.include "../../textproc/intltool/buildlink2.mk"
.include "../../mk/bsd.pkg.mk"
