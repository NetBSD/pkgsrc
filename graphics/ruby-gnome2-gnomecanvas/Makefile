# $NetBSD: Makefile,v 1.6 2006/07/25 16:49:05 minskim Exp $
#

PKGNAME=		ruby-gnome2-gnomecanvas-${VERSION}
COMMENT=		Ruby binding of GnomeCanvas-2.x
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	gnomecanvas

DEPENDS+=		ruby-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=		ruby-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

USE_TOOLS+=		pkg-config

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
