# $NetBSD: Makefile,v 1.63 2018/11/12 03:51:09 ryoon Exp $

DISTNAME=	gdl-3.10.0
PKGREVISION=	15
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/gdl/3.10/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://www.gnome.org/
COMMENT=	Gnome Devtool Libraries
LICENSE=	gnu-gpl-v3

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes
USE_TOOLS+=	pkg-config perl intltool msgfmt gmake

USE_PKGLOCALEDIR=	yes
PKGCONFIG_OVERRIDE+=	gdl-3.0.pc.in

.include "../../textproc/libxml2/buildlink3.mk"
.include "../../mk/jpeg.buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
