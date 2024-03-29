# $NetBSD: Makefile,v 1.108 2023/08/14 05:24:04 wiz Exp $

DISTNAME=	atk-2.38.0
PKGREVISION=	1
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/atk/
COMMENT=	Set of interfaces for accessibility
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config msgfmt
MESON_REQD+=	0.56.2

PKGCONFIG_OVERRIDE=		output/meson-private/atk.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

PYTHON_FOR_BUILD_ONLY=	tool

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
