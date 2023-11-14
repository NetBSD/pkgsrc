# $NetBSD: Makefile,v 1.12 2023/11/14 14:02:11 wiz Exp $
#

DISTNAME=		cairo-gobject-${VERSION}
COMMENT=		Ruby binding of cairo-gobject
PKGREVISION=		2
CATEGORIES=		graphics gnome

MAINTAINER=		tsutsui@NetBSD.org

CONFLICTS+=		ruby-gnome2-cairo-gobject-[0-9]*
SUPERSEDES+=		ruby-gnome2-cairo-gobject-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-glib2>=${VERSION}:../../devel/ruby-glib2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo>=1.16.2:../../graphics/ruby-cairo

.include "../../devel/ruby-glib2/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.18
.include "../../graphics/cairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
