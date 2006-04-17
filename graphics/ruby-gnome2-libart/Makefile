# $NetBSD: Makefile,v 1.3 2006/04/17 13:46:35 wiz Exp $
#

PKGNAME=		ruby-gnome2-libart-${VERSION}
COMMENT=		Ruby binding of Libart_lgpl
PKGREVISION=		2
CATEGORIES=		graphics

RUBY_EXTCONF_SUBDIRS=	libart

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
