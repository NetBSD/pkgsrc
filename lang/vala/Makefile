# $NetBSD: Makefile,v 1.1.1.1 2009/03/05 21:56:29 ahoka Exp $
#

DISTNAME=	vala-0.5.7
CATEGORIES=	lang gnome
MASTER_SITES=	http://download.gnome.org/sources/vala/0.5/
EXTRACT_SUFX=	.tar.bz2

MAINTAINER=	ahoka@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Vala
COMMENT=	Compiler for the GObject type system

PKG_DESTDIR_SUPPORT=	user-destdir

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	bison flex gmake pkg-config

PKGCONFIG_OVERRIDE+=	vala-1.0.pc.in

BUILDLINK_API_DEPENDS.glib2+=                   glib2>=2.12.0
BUILDLINK_API_DEPENDS.gtk2+=                    gtk2+>=2.10.0
BUILDLINK_DEPMETHOD.libxslt?=			build

.include "../../devel/glib2/buildlink3.mk"
.include "../../textproc/libxslt/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
