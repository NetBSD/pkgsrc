# $NetBSD: Makefile,v 1.1 2016/06/12 17:11:26 prlw1 Exp $

DISTNAME=	iagno-3.20.2
CATEGORIES=	games gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/iagno/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	prlw1@cam.ac.uk
HOMEPAGE=	https://wiki.gnome.org/Apps/Iagno
COMMENT=	Board game
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_TOOLS+=	gmake intltool msgfmt pkg-config

.include "../../audio/libcanberra-gtk3/buildlink3.mk"
.include "../../devel/glib2/schemas.mk"
.include "../../graphics/hicolor-icon-theme/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
