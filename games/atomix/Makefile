# $NetBSD: Makefile,v 1.78 2024/04/07 07:34:00 wiz Exp $

DISTNAME=		atomix-44.0
PKGREVISION=		3
CATEGORIES=		games
MASTER_SITES=		${MASTER_SITE_GNOME:=sources/atomix/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=		.tar.xz

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://gitlab.gnome.org/GNOME/atomix
COMMENT=		Puzzle game
LICENSE=		gnu-gpl-v2

USE_TOOLS+=	pkg-config

.include "../../devel/meson/build.mk"
.include "../../devel/gettext-tools/msgfmt-desktop.mk"
.include "../../games/libgnome-games-support1/buildlink3.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
