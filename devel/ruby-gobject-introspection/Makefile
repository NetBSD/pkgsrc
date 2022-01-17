# $NetBSD: Makefile,v 1.5 2022/01/17 15:17:15 tsutsui Exp $
#

DISTNAME=		gobject-introspection-${VERSION}
COMMENT=		Ruby binding of Gobject Introspection
CATEGORIES=		devel

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-gobject-introspection-[0-9]*
SUPERSEDES+=		ruby-gnome2-gobject-introspection-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2

# preserve generated files
GEM_KEEPBUILD=		\
	ext/gobject-introspection/gobject-introspection-enum-types.c \
	ext/gobject-introspection/gobject-introspection-enum-types.h \
	ext/gobject-introspection/rbgiversion.h

BUILDLINK_API_DEPENDS.gobject-introspection+=	gobject-introspection>=1.32.1
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
