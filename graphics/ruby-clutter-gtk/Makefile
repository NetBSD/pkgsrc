# $NetBSD: Makefile,v 1.35 2023/01/29 21:16:45 ryoon Exp $
#

DISTNAME=		clutter-gtk-${VERSION}
COMMENT=		Ruby binding of Clutter-GTK
PKGREVISION=		2
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-clutter-gtk-[0-9]*
SUPERSEDES+=		ruby-gnome2-clutter-gtk-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-clutter>=${VERSION}:../../graphics/ruby-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-clutter-gdk>=${VERSION}:../../graphics/ruby-clutter-gdk
DEPENDS+=	${RUBY_PKGPREFIX}-gtk3>=${VERSION}:../../x11/ruby-gtk3
DEPENDS+=	clutter-gtk>=1.0:../../graphics/clutter-gtk

.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../x11/ruby-gtk3/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
