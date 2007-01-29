# $NetBSD: Makefile,v 1.5 2007/01/29 06:42:34 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-libart-${VERSION}
COMMENT=		Ruby binding of Libart_lgpl
CATEGORIES=		graphics

CONFLICTS+=		ruby-gnome2-libart-[0-9]*

RUBY_EXTCONF_SUBDIRS=	libart

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../graphics/jpeg/buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
