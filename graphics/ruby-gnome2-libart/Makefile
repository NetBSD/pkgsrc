# $NetBSD: Makefile,v 1.12 2010/06/13 22:44:44 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-libart-${VERSION}
COMMENT=		Ruby binding of Libart_lgpl
PKGREVISION=		2
CATEGORIES=		graphics

CONFLICTS+=		ruby-gnome2-libart-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	libart

BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
