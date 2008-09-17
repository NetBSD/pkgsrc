# $NetBSD: Makefile,v 1.1 2008/09/17 00:21:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtkglext-${VERSION}
COMMENT=		Ruby binding of gtkglext
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtkglext

DEPENDS+=		${RUBY_PKGPREFIX}-opengl-[0-9]*:../../graphics/ruby-opengl
DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
