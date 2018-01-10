# $NetBSD: Makefile,v 1.89 2018/01/10 22:16:26 wiz Exp $

DISTNAME=		poppler-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		2
COMMENT=		Ruby binding of poppler-glib
CATEGORIES=		print

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby[0-9][0-9]-gnome2-poppler-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gio>=${VERSION}:../../devel/ruby-gnome2-gio
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject

BUILDLINK_API_DEPENDS.poppler-glib+=     poppler-glib>=0.8.0
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
