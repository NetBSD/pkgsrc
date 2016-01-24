# $NetBSD: Makefile,v 1.24 2016/01/24 05:03:23 tsutsui Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-gnome2-${VERSION}
PKGREVISION=	1
COMMENT=	Set of Ruby language bindings for GNOME2
CATEGORIES=	meta-pkgs gnome

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}nb1:../../devel/ruby-gnome2-atk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gio>=${VERSION}nb1:../../devel/ruby-gnome2-gio
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}nb1:../../devel/ruby-gnome2-glib
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}nb1:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}nb1:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}nb1:../../graphics/ruby-gnome2-cairo-gobject
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter>=${VERSION}nb1:../../graphics/ruby-gnome2-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter-gtk>=${VERSION}nb1:../../graphics/ruby-gnome2-clutter-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdk3>=${VERSION}nb1:../../graphics/ruby-gnome2-gdk3
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}nb1:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg>=${VERSION}nb1:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter-gstreamer>=${VERSION}nb1:../../multimedia/ruby-gnome2-clutter-gstreamer
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gstreamer>=${VERSION}nb1:../../multimedia/ruby-gnome2-gstreamer
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-poppler>=${VERSION}nb1:../../print/ruby-gnome2-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-webkit-gtk>=${VERSION}nb1:../../www/ruby-gnome2-webkit-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-webkit-gtk2>=${VERSION}nb1:../../www/ruby-gnome2-webkit-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}nb1:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}nb1:../../x11/ruby-gnome2-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtksourceview2>=${VERSION}nb1:../../x11/ruby-gnome2-gtksourceview2
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtksourceview3>=${VERSION}nb1:../../x11/ruby-gnome2-gtksourceview3
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-vte>=${VERSION}nb1:../../x11/ruby-gnome2-vte

META_PACKAGE=	yes

.include "../../lang/ruby/rubyversion.mk"
.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
