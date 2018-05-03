# $NetBSD: Makefile,v 1.70 2018/05/03 12:04:03 tsutsui Exp $
#

DISTNAME=		rsvg2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-rsvg-${VERSION}
COMMENT=		Ruby binding of librsvg
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.14.3:../../graphics/ruby-cairo
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
