# $NetBSD: Makefile,v 1.36 2013/10/10 14:42:16 ryoon Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-goocanvas-${VERSION}
COMMENT=		Ruby binding of GooCanvas
PKGREVISION=		2
CATEGORIES=		graphics gnome

CONFLICTS+=		ruby[0-9][0-9]-gnome2-goocanvas-[0-9]*

RUBY_EXTCONF_SUBDIRS=	goocanvas

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3

.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../graphics/goocanvas2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
