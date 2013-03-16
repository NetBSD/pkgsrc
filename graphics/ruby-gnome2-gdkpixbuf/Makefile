# $NetBSD: Makefile,v 1.33 2013/03/16 12:25:48 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf-${VERSION}
COMMENT=		Ruby binding of GdkPixbuf-2.x
CATEGORIES=		graphics devel

CONFLICTS+=		ruby-gnome2-gdkpixbuf-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gdkpixbuf-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gdk_pixbuf2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
