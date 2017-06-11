# $NetBSD: Makefile,v 1.25 2017/06/11 05:51:40 tsutsui Exp $
#

DISTNAME=		gdk3-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of GDK3
CATEGORIES=		graphics

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gdk3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=		gtk3+>=3.4.2:../../x11/gtk3

.include "../../x11/gtk3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
