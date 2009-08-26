# $NetBSD: Makefile,v 1.2 2009/08/26 19:57:49 sno Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-gtk-${VERSION}
COMMENT=		Ruby binding for Clutter GTK+ widget
PKGREVISION=		1
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core

RUBY_EXTCONF_SUBDIRS=	clutter-gtk

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../x11/ruby-gnome2-gtk/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
