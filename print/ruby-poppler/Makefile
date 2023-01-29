# $NetBSD: Makefile,v 1.24 2023/01/29 21:17:37 ryoon Exp $
#

DISTNAME=		poppler-${VERSION}
COMMENT=		Ruby binding of poppler-glib
PKGREVISION=		2
CATEGORIES=		print

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-poppler-[0-9]*
SUPERSEDES+=		ruby-gnome2-poppler-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gio2>=${VERSION}:../../devel/ruby-gio2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject

.include "../../devel/ruby-gio2/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler-glib+=     poppler-glib>=0.79.0nb1
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
