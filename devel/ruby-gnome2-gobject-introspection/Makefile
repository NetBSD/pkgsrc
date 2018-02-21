# $NetBSD: Makefile,v 1.7 2018/02/21 16:59:59 jperkin Exp $
#

DISTNAME=		gobject-introspection-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of Gobject Introspection
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gobject-introspection-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.32.1
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
