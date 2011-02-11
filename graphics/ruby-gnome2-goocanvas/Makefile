# $NetBSD: Makefile,v 1.11 2011/02/11 13:50:13 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-goocanvas-${VERSION}
COMMENT=		Ruby binding of GooCanvas
CATEGORIES=		graphics gnome

CONFLICTS+=		ruby[0-9][0-9]-gnome2-goocanvas-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	goocanvas

.include "../../graphics/goocanvas/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
