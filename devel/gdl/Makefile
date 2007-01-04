# $NetBSD: Makefile,v 1.1.1.1 2007/01/04 00:27:28 rillig Exp $
#

DISTNAME=	gdl-0.6.1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdl/0.6/}
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	rillig@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Gnome Devtool Libraries

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl

PKGCONFIG_OVERRIDE+=	gdl-1.0.pc.in

.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libglade2/buildlink3.mk"
.include "../../devel/libgnome/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../textproc/libxml2/buildlink3.mk"
.include "../../graphics/jpeg/buildlink3.mk"
# XXX: *** Warning: linker path does not have real file for library -lgnome-keyring.
.include "../../security/gnome-keyring/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
