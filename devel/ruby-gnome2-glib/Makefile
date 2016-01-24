# $NetBSD: Makefile,v 1.26 2016/01/24 05:03:22 tsutsui Exp $
#

DISTNAME=		glib2-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-glib-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-glib-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-pkg-config-[0-9]*:../../devel/ruby-pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
