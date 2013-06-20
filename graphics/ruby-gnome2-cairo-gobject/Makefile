# $NetBSD: Makefile,v 1.3 2013/06/20 09:12:14 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject-${VERSION}
COMMENT=		Ruby binding of cairo-gobject
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	cairo-gobject

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
