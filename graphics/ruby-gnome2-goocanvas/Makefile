# $NetBSD: Makefile,v 1.3 2009/10/12 03:09:33 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-goocanvas-${VERSION}
COMMENT=		Ruby binding of GooCanvas
CATEGORIES=		graphics gnome

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	goocanvas

USE_TOOLS+=		pkg-config

.include "../../graphics/goocanvas/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
