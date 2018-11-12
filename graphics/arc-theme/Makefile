# $NetBSD: Makefile,v 1.12 2018/11/12 03:52:08 ryoon Exp $

DISTNAME=	arc-theme
PKGNAME=	arc-theme-20170302
PKGREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_GITHUB:=horst3180/}

MAINTAINER=	youri@NetBSD.org
HOMEPAGE=	https://github.com/horst3180/arc-theme/
COMMENT=	Arch theme for GTK2, GTK3 and desktops
LICENSE=	gnu-gpl-v3

GITHUB_PROJECT=	arc-theme
GITHUB_TAG=	20170302

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	automake pkg-config intltool autoreconf
DEPENDS+=	gtk2-engines-murrine-[0-9]*:../../x11/gtk2-engines-murrine
DEPENDS+=	gnome-themes-standard-[0-9]*:../../graphics/gnome-themes-standard

pre-configure:
	${LN} -s 3.20 ${WRKSRC}/common/gtk-3.0/3.22
	${LN} -s 3.20 ${WRKSRC}/common/gnome-shell/3.22
	${LN} -s 3.20 ${WRKSRC}/common/gtk-3.0/3.24
	${LN} -s 3.20 ${WRKSRC}/common/gnome-shell/3.24
	cd ${WRKSRC} && autoreconf --verbose --force --install

.include "../../x11/gtk2/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
