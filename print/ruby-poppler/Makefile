# $NetBSD: Makefile,v 1.34 2024/03/11 21:16:00 wiz Exp $

DISTNAME=		poppler-${VERSION}
COMMENT=		Ruby binding of poppler-glib
PKGREVISION=		1
CATEGORIES=		print

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-poppler-[0-9]*
SUPERSEDES+=		ruby-gnome2-poppler-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gio2>=${VERSION}:../../devel/ruby-gio2
DEPENDS+=		${RUBY_PKGPREFIX}-cairo-gobject>=${VERSION}:../../graphics/ruby-cairo-gobject

.include "../../devel/ruby-gio2/buildlink3.mk"
BUILDLINK_API_DEPENDS.poppler+=	poppler>=23.12.0
.include "../../print/poppler/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
