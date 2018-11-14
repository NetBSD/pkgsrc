# $NetBSD: Makefile,v 1.19 2018/11/14 22:21:40 kleink Exp $

DISTNAME=		gnome-icon-theme-symbolic-3.12.0
PKGREVISION=		8
CATEGORIES=		graphics gnome
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/gnome-icon-theme-symbolic/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://www.gnome.org/
COMMENT=		Symbolic icons for the GNOME icon sets
LICENSE=		cc-by-sa-v3.0

GNU_CONFIGURE=		yes
USE_TOOLS+=		gmake pkg-config

PKGCONFIG_OVERRIDE+=	gnome-icon-theme-symbolic.pc.in

# The list of installed files depends on the version of
# icon-naming-utils, so be sure that this dependency corresponds to
# the current pkgsrc version.
BUILDLINK_API_DEPENDS.icon-naming-utils+=	icon-naming-utils>=0.8.90
.include "../../graphics/icon-naming-utils/buildlink3.mk"
.include "../../graphics/gnome-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
