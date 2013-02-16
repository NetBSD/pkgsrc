# $NetBSD: Makefile,v 1.19 2013/02/16 11:22:28 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-gtk-${VERSION}
COMMENT=		Ruby binding for Clutter GTK+ widget
PKGREVISION=		16
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core

RUBY_EXTCONF_SUBDIRS=	clutter-gtk
RUBY_VERSION_SUPPORTED= 18

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter08-gtk/buildlink3.mk"
.include "../../x11/ruby-gnome2-gtk/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
