# $NetBSD: Makefile,v 1.35 2019/10/07 09:28:12 prlw1 Exp $

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

.include "../../devel/meson/build.mk"
.include "../../mk/bsd.pkg.mk"
