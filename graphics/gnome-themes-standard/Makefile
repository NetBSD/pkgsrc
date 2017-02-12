# $NetBSD: Makefile,v 1.6 2017/02/12 06:25:28 ryoon Exp $

DISTNAME=	gnome-themes-standard-3.20.2
PKGREVISION=	3
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-themes-standard/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	http://www.gnome.org/
COMMENT=	Default themes for the GNOME desktop
LICENSE=	gnu-gpl-v2

GNU_CONFIGURE=	yes
USE_TOOLS+=	msgfmt pkg-config intltool

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
