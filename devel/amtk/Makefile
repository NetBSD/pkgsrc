# $NetBSD: Makefile,v 1.15 2024/10/20 14:03:31 wiz Exp $

DISTNAME=	amtk-5.0.2
PKGREVISION=	11
CATEGORIES=	devel gnome
MASTER_SITES=	${MASTER_SITE_GNOME:=sources/amtk/5.0/}
EXTRACT_SUFX=	.tar.xz

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://wiki.gnome.org/Projects/Amtk
COMMENT=	Actions, Menus and Toolbars Kit for GTK applications
LICENSE=	gnu-lgpl-v2.1

GNU_CONFIGURE=	yes
USE_LIBTOOL=	yes

USE_TOOLS+=	pkg-config gmake
USE_TOOLS+=	msgfmt msgmerge xgettext

PKGCONFIG_OVERRIDE+=	amtk.pc.in

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../x11/gtk3/buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
