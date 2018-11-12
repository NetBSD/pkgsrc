# $NetBSD: Makefile,v 1.62 2018/11/12 03:51:14 ryoon Exp $
#

DISTNAME=		pango-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		1
COMMENT=		Ruby binding of pango-1.x
CATEGORIES=		devel fonts

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-pango-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/ruby-gnome2-gobject-introspection/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
