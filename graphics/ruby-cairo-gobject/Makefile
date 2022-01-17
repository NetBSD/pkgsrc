# $NetBSD: Makefile,v 1.7 2022/01/17 15:17:15 tsutsui Exp $
#

DISTNAME=		cairo-gobject-${VERSION}
COMMENT=		Ruby binding of cairo-gobject
CATEGORIES=		graphics gnome

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-cairo-gobject-[0-9]*
SUPERSEDES+=		ruby-gnome2-cairo-gobject-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.16.2:../../graphics/ruby-cairo

.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
