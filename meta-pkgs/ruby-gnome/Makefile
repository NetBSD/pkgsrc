# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:38 tsutsui Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-gnome-${VERSION}
COMMENT=	Set of Ruby language bindings for GNOME
CATEGORIES=	meta-pkgs gnome

MAINTAINER=	pkgsrc-users@NetBSD.org

CONFLICTS+=	ruby-gnome2-[0-9]*
SUPERSEDES+=	ruby-gnome2-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-atk>=${VERSION}:../../devel/ruby-atk
DEPENDS+=	${RUBY_PKGPREFIX}-gio2>=${VERSION}:../../devel/ruby-gio2
DEPENDS+=	${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2
DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject
DEPENDS+=	${RUBY_PKGPREFIX}-pango>=${VERSION}:../../devel/ruby-pango

DEPENDS+=	${RUBY_PKGPREFIX}-clutter>=${VERSION}:../../graphics/ruby-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gdk>=${VERSION}:../../graphics/ruby-clutter-gdk
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gtk>=${VERSION}:../../graphics/ruby-clutter-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gdk3>=${VERSION}:../../graphics/ruby-gdk3
DEPENDS+=	${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=	${RUBY_PKGPREFIX}-rsvg2>=${VERSION}:../../graphics/ruby-rsvg2
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gstreamer>=${VERSION}:../../multimedia/ruby-clutter-gstreamer
DEPENDS+=	${RUBY_PKGPREFIX}-gstreamer>=${VERSION}:../../multimedia/ruby-gstreamer
DEPENDS+=	${RUBY_PKGPREFIX}-poppler>=${VERSION}:../../print/ruby-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-webkit-gtk>=${VERSION}:../../www/ruby-webkit-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-webkit-gtk2>=${VERSION}:../../www/ruby-webkit-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gtk2>=${VERSION}:../../x11/ruby-gtk2
DEPENDS+=	${RUBY_PKGPREFIX}-gtk3>=${VERSION}:../../x11/ruby-gtk3
DEPENDS+=	${RUBY_PKGPREFIX}-gtksourceview2>=${VERSION}:../../x11/ruby-gtksourceview2
DEPENDS+=	${RUBY_PKGPREFIX}-gtksourceview3>=${VERSION}:../../x11/ruby-gtksourceview3
DEPENDS+=	${RUBY_PKGPREFIX}-vte>=${VERSION}:../../x11/ruby-vte

META_PACKAGE=	yes

.include "../../lang/ruby/rubyversion.mk"
.include "Makefile.common"
.include "../../mk/bsd.pkg.mk"
