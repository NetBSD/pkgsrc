# $NetBSD: Makefile,v 1.2 2016/06/14 00:39:16 youri Exp $

DISTNAME=	arc-theme
PKGNAME=	arc-theme-20160605
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=horst3180/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/horst3180/arc-theme/
COMMENT=	Arch theme for GTK2, GTK3 and desktops
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	arc-theme
GITHUB_TAG=	20160605

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake pkg-config intltool
DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine
DEPENDS+=	gnome-themes-standard-[0-9]*:../../graphics/gnome-themes-standard

pre-configure:
		cd ${WRKSRC} && ./autogen.sh

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
