# $NetBSD: Makefile,v 1.26 2016/02/04 12:13:30 wiz Exp $

DISTNAME=	libgee-0.18.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libgee
COMMENT=	Library providing GObject-based interfaces and classes
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=		pkg-config gmake

PKGCONFIG_OVERRIDE+=	gee-0.8.pc.in

TEST_TARGET=	check

BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.vala:= build
BUILDLINK_API_DEPENDS.vala+=	vala>=0.25.1
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
