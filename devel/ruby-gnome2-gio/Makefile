# $NetBSD: Makefile,v 1.19 2016/12/25 18:58:05 tsutsui Exp $
#

DISTNAME=		gio2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gio-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of gio-2.0.x
CATEGORIES=		devel

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gio-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/ruby-gnome2-gobject-introspection/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
