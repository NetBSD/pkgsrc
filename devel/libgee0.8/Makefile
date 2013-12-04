# $NetBSD: Makefile,v 1.6 2013/12/04 16:43:47 drochner Exp $

DISTNAME=	libgee-0.8.8
PKGNAME=	${DISTNAME:S/libgee/libgee0.8/}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/0.8/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://live.gnome.org/Libgee
COMMENT=	Library providing GObject-based interfaces and classes (v0.8)
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		pkg-config gmake

# to regenerate after patches
#BUILDLINK_DEPMETHOD.vala:= build
#.include "../../lang/vala018/buildlink3.mk"

PKGCONFIG_OVERRIDE+=	gee-0.8.pc.in

TEST_TARGET=	check

BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
