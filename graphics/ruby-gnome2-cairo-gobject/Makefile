# $NetBSD: Makefile,v 1.18 2019/01/27 02:23:39 tsutsui Exp $
#

DISTNAME=		cairo-gobject-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of cairo-gobject
CATEGORIES=		graphics gnome

MAINTAINER=		tsutsui@NetBSD.org

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.16.2:../../graphics/ruby-cairo

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
