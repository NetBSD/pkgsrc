# $NetBSD: Makefile,v 1.10 2016/01/11 23:49:33 wiz Exp $

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-cairo-gobject-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of cairo-gobject
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	cairo-gobject

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/ruby-cairo/buildlink3.mk"
.include "../../graphics/cairo-gobject/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
