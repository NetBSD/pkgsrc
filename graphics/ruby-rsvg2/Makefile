# $NetBSD: Makefile,v 1.2 2020/03/08 16:50:08 wiz Exp $
#

DISTNAME=		rsvg2-${VERSION}
COMMENT=		Ruby binding of librsvg
PKGREVISION=		1
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-rsvg-[0-9]*
SUPERSEDES+=		ruby-gnome2-rsvg-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.14.3:../../graphics/ruby-cairo
DEPENDS+=		${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
