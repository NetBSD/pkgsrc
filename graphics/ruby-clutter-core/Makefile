# $NetBSD: Makefile,v 1.7 2010/09/23 19:26:11 joerg Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-core-${VERSION}
COMMENT=		Ruby binding for Clutter Core library
PKGREVISION=		4
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	clutter

USE_TOOLS+=		pkg-config

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
