# $NetBSD: Makefile,v 1.104 2020/07/16 06:09:34 adam Exp $

DISTNAME=	atk-2.36.0
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/atk/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://developer.gnome.org/atk/
COMMENT=	Set of interfaces for accessibility
LICENSE=	gnu-lgpl-v2

USE_LANGUAGES=	c99
USE_TOOLS+=	pkg-config msgfmt

PKGCONFIG_OVERRIDE=		output/meson-private/atk.pc
PKGCONFIG_OVERRIDE_STAGE=	pre-install
MAKE_ENV+=			LD_LIBRARY_PATH=${WRKSRC}/output/${PKGBASE}

.include "../../devel/gettext-lib/buildlink3.mk"
BUILDLINK_API_DEPENDS.glib2+=	glib2>=2.38.0
.include "../../devel/glib2/buildlink3.mk"
BUILDLINK_DEPMETHOD.gobject-introspection:= build
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
