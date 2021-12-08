# $NetBSD: Makefile,v 1.4 2021/12/08 16:02:03 adam Exp $
#

DISTNAME=		gio2-${VERSION}
COMMENT=		Ruby binding of gio-2.0.x
PKGREVISION=		1
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gio-[0-9]*
SUPERSEDES+=		ruby-gnome2-gio-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
