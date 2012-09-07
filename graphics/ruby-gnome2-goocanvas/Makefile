# $NetBSD: Makefile,v 1.21 2012/09/07 19:16:53 adam Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-goocanvas-${VERSION}
COMMENT=		Ruby binding of GooCanvas
PKGREVISION=		1
CATEGORIES=		graphics gnome

CONFLICTS+=		ruby[0-9][0-9]-gnome2-goocanvas-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	goocanvas

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

.include "../../graphics/goocanvas/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
