# $NetBSD: Makefile,v 1.55 2025/12/21 14:06:30 prlw1 Exp $

DISTNAME=	libgee-0.20.8
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/libgee/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Libgee
COMMENT=	Library providing GObject-based interfaces and classes
LICENSE=	gnu-lgpl-v2.1

USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config gmake
GNU_CONFIGURE=	yes
TEST_TARGET=	check

.include "../../mk/compiler.mk"
.if ${CC_VERSION:Mgcc-14.*} || ${CC_VERSION:Mgcc-15.*}
CFLAGS+=	-Wno-incompatible-pointer-types
.endif

PKGCONFIG_OVERRIDE+=	gee-0.8.pc.in

BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.36
.include "../../devel/glib2/buildlink3.mk"
.include "../../lang/vala/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
