# $NetBSD: Makefile,v 1.13 2023/01/29 21:16:05 ryoon Exp $

DISTNAME=	gnome-font-viewer-3.27.0
PKGREVISION=	12
CATEGORIES=	fonts
MASTER_SITES=	${MASTER_SITE_GITHUB:=GNOME/}
GITHUB_PROJECT=	gnome-font-viewer
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	ryoon@NetBSD.org
HOMEPAGE=	https://github.com/GNOME/gnome-font-viewer
COMMENT=	Font viewer for GNOME 3 desktop environment
LICENSE=	gnu-gpl-v2

USE_LANGUAGES+=	c
USE_TOOLS+=	msgfmt pkg-config

MAKE_ENV+=	WRKSRC=${WRKSRC}
MAKE_ENV+=	PKGVERSION_NOREV=${PKGVERSION_NOREV}
MAKE_ENV+=	PKGLOCALEDIR=${PKGLOCALEDIR}

.include "../../sysutils/gsettings-desktop-schemas/buildlink3.mk"
.include "../../x11/gnome-desktop3/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
