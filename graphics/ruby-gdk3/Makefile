# $NetBSD: Makefile,v 1.6 2021/08/22 17:02:42 tsutsui Exp $
#

DISTNAME=		gdk3-${VERSION}
COMMENT=		Ruby binding of GDK3
CATEGORIES=		graphics

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gdk3-[0-9]*
SUPERSEDES+=		ruby-gnome2-gdk3-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject
DEPENDS+=		${RUBY_PKGPREFIX}-pango>=${VERSION}:../../devel/ruby-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=		gtk3+>=3.4.2:../../x11/gtk3

.include "../../x11/gtk3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
