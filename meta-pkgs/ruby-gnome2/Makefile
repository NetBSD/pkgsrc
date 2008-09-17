# $NetBSD: Makefile,v 1.11 2008/09/17 00:21:48 obache Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-gnome2-${VERSION}
COMMENT=	Set of Ruby language bindings for GNOME2
CATEGORIES=	meta-pkgs gnome

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-bonobo>=${VERSION}:../../devel/ruby-gnome2-bonobo
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-bonoboui>=${VERSION}:../../devel/ruby-gnome2-bonoboui
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gconf>=${VERSION}:../../devel/ruby-gnome2-gconf
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-libglade>=${VERSION}:../../devel/ruby-gnome2-libglade
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtkglext>=${VERSION}:../../graphics/ruby-gnome2-gtkglext
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg>=${VERSION}:../../graphics/ruby-gnome2-rsvg
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gstreamer>=${VERSION}:../../multimedia/ruby-gnome2-gstreamer
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomeprint>=${VERSION}:../../print/ruby-gnome2-gnomeprint
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomeprintui>=${VERSION}:../../print/ruby-gnome2-gnomeprintui
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-poppler>=${VERSION}:../../print/ruby-gnome2-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomevfs>=${VERSION}:../../sysutils/ruby-gnome2-gnomevfs
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtkhtml2>=${VERSION}:../../www/ruby-gnome2-gtkhtml2
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtkmozembed>=${VERSION}:../../www/ruby-gnome2-gtkmozembed
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtksourceview>=${VERSION}:../../x11/ruby-gnome2-gtksourceview
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-panelapplet>=${VERSION}:../../x11/ruby-gnome2-panelapplet
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-vte>=${VERSION}:../../x11/ruby-gnome2-vte

META_PACKAGE=	yes

.include "../../lang/ruby/rubyversion.mk"
.include "Makefile.common"
