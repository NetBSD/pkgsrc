# $NetBSD: Makefile,v 1.4 2013/09/02 19:51:09 adam Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject-${VERSION}
COMMENT=		Ruby binding of cairo-gobject
PKGREVISION=		1
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	cairo-gobject

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
