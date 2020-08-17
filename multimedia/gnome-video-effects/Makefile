# $NetBSD: Makefile,v 1.2 2020/08/17 20:19:38 leot Exp $

DISTNAME=	gnome-video-effects-0.5.0
PKGREVISION=	1
CATEGORIES=	multimedia gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-video-effects/0.5/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/GnomeVideoEffects
COMMENT=	Collection of GStreamer effects for GNOME
LICENSE=	gnu-lgpl-v2

USE_TOOLS+=	pkg-config msgfmt xgettext

PYTHON_FOR_BUILD_ONLY=	tool

PKGCONFIG_OVERRIDE+=	gnome-video-effects.pc.in

# XXX msgfmt: unknown option -- desktop
_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../devel/meson/build.mk"
.include "../../multimedia/frei0r/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
