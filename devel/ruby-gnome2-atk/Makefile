# $NetBSD: Makefile,v 1.4 2007/01/29 06:42:33 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-atk-${VERSION}
COMMENT=		Ruby binding of ATK-1.0.x or later
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-atk-[0-9]*

RUBY_EXTCONF_SUBDIRS=	atk

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../devel/atk/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
