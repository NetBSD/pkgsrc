# $NetBSD: Makefile,v 1.3 2009/10/26 08:39:36 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-cairo-${VERSION}
COMMENT=		Ruby binding for Clutter Cairo library
PKGREVISION=		2
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	${RUBY_PKGPREFIX}-clutter-core>=${VERSION}:../../graphics/ruby-clutter-core

RUBY_EXTCONF_SUBDIRS=	clutter-cairo

USE_TOOLS+=	pkg-config

BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter-cairo/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
