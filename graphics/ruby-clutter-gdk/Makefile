# $NetBSD: Makefile,v 1.13 2023/02/03 20:02:57 tsutsui Exp $
#

DISTNAME=		clutter-gdk-${VERSION}
COMMENT=		Ruby binding of GDK specific API of Clutter
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-clutter-gdk-[0-9]*
SUPERSEDES+=		ruby-gnome2-clutter-gdk-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-clutter>=${VERSION}:../../graphics/ruby-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gdk3>=${VERSION}:../../graphics/ruby-gdk3

.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../graphics/ruby-gdk3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
