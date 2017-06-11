# $NetBSD: Makefile,v 1.6 2017/06/11 05:51:40 tsutsui Exp $
#

DISTNAME=		gobject-introspection-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of Gobject Introspection
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gobject-introspection-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gobject-introspection-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.32.1
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
