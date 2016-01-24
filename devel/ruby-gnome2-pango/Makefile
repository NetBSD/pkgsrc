# $NetBSD: Makefile,v 1.49 2016/01/24 05:03:23 tsutsui Exp $
#

DISTNAME=		pango-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		1
COMMENT=		Ruby binding of pango-1.x
CATEGORIES=		devel fonts

CONFLICTS+=		ruby-gnome2-pango-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-pango-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.14.3:../../graphics/ruby-cairo

.include "../../devel/pango/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
