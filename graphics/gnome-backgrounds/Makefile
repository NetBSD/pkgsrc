# $NetBSD: Makefile,v 1.34 2018/06/13 19:35:51 youri Exp $

DISTNAME=	gnome-backgrounds-3.28.0
CATEGORIES=	graphics gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gnome-backgrounds/3.28/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Set of background images for the GNOME Desktop
LICENSE=	gnu-gpl-v2

USE_TOOLS+=		gmake intltool msgfmt

_TOOLS_USE_PKGSRC.msgfmt=	yes

.include "../../devel/py-meson/build.mk"
.include "../../mk/bsd.pkg.mk"
