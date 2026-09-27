# $NetBSD: Makefile,v 1.9 2026/09/27 11:35:49 tnn Exp $
#

DISTNAME=		glib2-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
PKGREVISION=		2
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-glib-[0-9]*
SUPERSEDES+=		ruby-gnome2-glib-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-native-package-installer>=1.0.3:../../devel/ruby-native-package-installer
DEPENDS+=		${RUBY_PKGPREFIX}-pkg-config>=1.3.5:../../devel/ruby-pkg-config

# preserve generated files
GEM_KEEPBUILD=		ext/glib2/glib-enum-types.c \
			ext/glib2/glib-enum-types.h

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
