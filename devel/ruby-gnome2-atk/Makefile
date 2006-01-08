# $NetBSD: Makefile,v 1.1.1.1 2006/01/08 03:10:18 minskim Exp $
#

PKGNAME=		ruby-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../devel/atk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
