# $NetBSD: Makefile,v 1.19 2024/02/23 11:25:29 tsutsui Exp $
#

DISTNAME=		clutter-${VERSION}
COMMENT=		Ruby binding of Clutter
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-clutter-[0-9]*
SUPERSEDES+=		ruby-gnome2-clutter-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-pango>=${VERSION}:../../devel/ruby-pango
DEPENDS+=	${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject
DEPENDS+=	clutter>=1.0:../../graphics/clutter

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-pango/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
