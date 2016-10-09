# $NetBSD: Makefile,v 1.6 2016/10/09 15:43:30 tsutsui Exp $
#

DISTNAME=		clutter-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of Clutter
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject
DEPENDS+=	clutter>=1.0:../../graphics/clutter

.include "../../graphics/clutter/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
