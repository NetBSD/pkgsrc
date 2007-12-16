# $NetBSD: Makefile,v 1.8 2007/12/16 13:55:47 drochner Exp $
#

DISTNAME=	gdl-0.7.7
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdl/0.7/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Devtool Libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool msgfmt gmake

PKGCONFIG_OVERRIDE+=	gdl-1.0.pc.in
PKGCONFIG_OVERRIDE+=	gdl-gnome-1.0.pc.in

.include "../../devel/libglade/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
