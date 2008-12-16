# $NetBSD: Makefile,v 1.1.1.1 2008/12/16 12:26:20 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-core-${VERSION}
COMMENT=		Ruby binding for Clutter Core library
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	clutter

USE_TOOLS+=		pkg-config

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
