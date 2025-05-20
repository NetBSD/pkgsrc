# $NetBSD: Makefile,v 1.1 2025/05/20 10:33:04 nia Exp $

DISTNAME=	vertex-theme-20170128
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=horst3180/}
GITHUB_TAG=	${PKGVERSION_NOREV}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/horst3180/vertex-theme
COMMENT=	Theme for GTK2, GTK3, Xfce, and MATE
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake pkg-config intltool autoreconf
DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine
DEPENDS+=	gnome-themes-standard-[0-9]*:../../graphics/gnome-themes-standard

CONFIGURE_ARGS+=	--disable-gnome-shell
CONFIGURE_ARGS+=	--disable-unity
CONFIGURE_ARGS+=	--with-gnome=3.20

pre-configure:
	cd ${WRKSRC} && autoreconf --verbose --force --install

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
