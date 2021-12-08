# $NetBSD: Makefile,v 1.7 2021/12/08 16:02:03 adam Exp $
#

DISTNAME=		pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
PKGREVISION=		1
CATEGORIES=		devel fonts

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-pango-[0-9]*
SUPERSEDES+=		ruby-gnome2-pango-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject

BUILDLINK_API_DEPENDS.pango+=	pango>=1.44.0
.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
