# $NetBSD: Makefile,v 1.22 2013/03/14 19:20:20 drochner Exp $
#

DISTNAME=	libgee-0.6.8
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/0.6/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Libgee
COMMENT=	Library providing GObject-based interfaces and classes (v0.6)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		pkg-config gmake

# to regenerate after patches
#BUILDLINK_DEPMETHOD.vala:= build
#.include "../../lang/vala018/buildlink3.mk"

PKGCONFIG_OVERRIDE+=	gee-1.0.pc.in

TEST_TARGET=	check

BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
