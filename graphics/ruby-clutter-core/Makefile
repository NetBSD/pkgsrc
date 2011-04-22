# $NetBSD: Makefile,v 1.12 2011/04/22 13:43:50 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-core-${VERSION}
COMMENT=		Ruby binding for Clutter Core library
PKGREVISION=		9
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	clutter

USE_TOOLS+=		pkg-config

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
