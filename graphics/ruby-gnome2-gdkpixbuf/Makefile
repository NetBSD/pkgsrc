# $NetBSD: Makefile,v 1.38 2016/08/03 10:22:56 adam Exp $
#

DISTNAME=		gdk_pixbuf2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of GdkPixbuf-2.x
CATEGORIES=		graphics devel

CONFLICTS+=		ruby-gnome2-gdkpixbuf-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gdkpixbuf-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/gdk-pixbuf2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
