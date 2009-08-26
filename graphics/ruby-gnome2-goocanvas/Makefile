# $NetBSD: Makefile,v 1.2 2009/08/26 19:57:49 sno Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-goocanvas-${VERSION}
COMMENT=		Ruby binding of GooCanvas
PKGREVISION=		1
CATEGORIES=		graphics gnome

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	goocanvas

USE_TOOLS+=		pkg-config

.include "../../graphics/goocanvas/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
