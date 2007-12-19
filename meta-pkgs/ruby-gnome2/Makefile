# $NetBSD: Makefile,v 1.9 2007/12/19 12:27:30 rillig Exp $
#

PKGNAME=	${RUBY_PKGPREFIX}-gnome2-${VERSION}
PKGREVISION=	2
COMMENT=	Set of Ruby language bindings for GNOME2
CATEGORIES=	meta-pkgs gnome

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-atk>=${VERSION}:../../devel/ruby-gnome2-atk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomecanvas>=${VERSION}:../../graphics/ruby-gnome2-gnomecanvas
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gnomeprint>=${VERSION}:../../print/ruby-gnome2-gnomeprint
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-panelapplet>=${VERSION}:../../x11/ruby-gnome2-panelapplet
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-poppler>=${VERSION}:../../print/ruby-gnome2-poppler
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-rsvg>=${VERSION}:../../graphics/ruby-gnome2-rsvg

META_PACKAGE=	yes

.include "../../lang/ruby/rubyversion.mk"
.include "Makefile.common"
