# $NetBSD: Makefile,v 1.11 2023/11/12 13:20:56 wiz Exp $

DISTNAME=	amtk-5.0.2
PKGREVISION=	7
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
