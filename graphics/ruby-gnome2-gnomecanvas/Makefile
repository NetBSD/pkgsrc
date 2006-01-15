# $NetBSD: Makefile,v 1.2 2006/01/15 16:26:59 minskim Exp $
#

PKGNAME=		ruby-gnome2-gnomecanvas-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of GnomeCanvas-2.x
CATEGORIES=		graphics gnome

RUBY_EXTCONF_SUBDIRS=	gnomecanvas

DEPENDS+=		ruby-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=		ruby-gnome2-gtk>=${VERSION}nb1:../../x11/ruby-gnome2-gtk

USE_TOOLS+=		pkg-config

.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
