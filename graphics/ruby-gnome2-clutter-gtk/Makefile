# $NetBSD: Makefile,v 1.4 2016/08/03 10:22:56 adam Exp $
#

DISTNAME=		clutter-gtk-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		1
COMMENT=		Ruby binding of Clutter-GTK
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter>=${VERSION}:../../graphics/ruby-gnome2-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3
DEPENDS+=	clutter-gtk>=1.0:../../graphics/clutter-gtk

.include "../../graphics/clutter-gtk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
