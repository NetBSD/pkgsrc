# $NetBSD: Makefile,v 1.106 2026/09/02 19:01:25 wiz Exp $

DISTNAME=	gdl-3.34.0
PKGREVISION=	37
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdl/${PKGVERSION_NOREV:R}/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://gitlab.gnome.org/GNOME/gdl
COMMENT=	Gnome Devtool Libraries
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool msgfmt gmake

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	gdl-3.0.pc.in

CFLAGS+=	-Wno-implicit-function-declaration
CFLAGS+=	-Wno-incompatible-pointer-types

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
