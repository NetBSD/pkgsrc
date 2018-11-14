# $NetBSD: Makefile,v 1.12 2018/11/14 22:21:46 kleink Exp $
#

DISTNAME=		clutter-gdk-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		2
COMMENT=		Ruby binding of GDK specific API of Clutter
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter>=${VERSION}:../../graphics/ruby-gnome2-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdk3>=${VERSION}:../../graphics/ruby-gnome2-gdk3

.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
