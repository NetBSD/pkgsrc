# $NetBSD: Makefile,v 1.86 2022/07/22 17:07:10 micha Exp $

DISTNAME=	vala-0.56.2
PKGREVISION=	1
CATEGORIES=	lang gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/vala/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Vala
COMMENT=	Compiler for the GObject type system
LICENSE=	gnu-lgpl-v2.1

BUILD_DEPENDS+=	libxslt-[0-9]*:../../textproc/libxslt
BUILD_DEPENDS+=	docbook-xml-[0-9]*:../../textproc/docbook-xml

USE_LIBTOOL=		yes
USE_TOOLS+=		bison flex gmake pkg-config
GNU_CONFIGURE=		yes
PKGCONFIG_OVERRIDE+=	libvala.pc.in
PKGCONFIG_OVERRIDE+=	vapigen/vapigen.pc.in

# as of 0.54.5
# 1 of 1291 tests failed
# FAIL: dbus/filedescriptor-errors
TEST_TARGET=		check

BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.48.0
.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/libltdl/buildlink3.mk"
.include "../../graphics/graphviz/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
