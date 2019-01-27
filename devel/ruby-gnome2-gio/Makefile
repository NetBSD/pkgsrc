# $NetBSD: Makefile,v 1.23 2019/01/27 02:23:39 tsutsui Exp $
#

DISTNAME=		gio2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gio-${VERSION}
COMMENT=		Ruby binding of gio-2.0.x
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/ruby-gnome2-gobject-introspection/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
