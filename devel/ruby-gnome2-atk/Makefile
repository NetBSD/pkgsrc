# $NetBSD: Makefile,v 1.2 2006/02/05 23:08:52 joerg Exp $
#

PKGNAME=		ruby-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
PKGREVISION=		1
CATEGORIES=		devel

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../devel/atk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
