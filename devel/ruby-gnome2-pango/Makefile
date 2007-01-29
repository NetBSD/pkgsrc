# $NetBSD: Makefile,v 1.6 2007/01/29 06:42:34 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
CATEGORIES=		devel fonts

CONFLICTS+=		ruby-gnome2-pango-[0-9]*

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

USE_TOOLS+=		pkg-config

INSTALL_TARGET=		install

.include "../../devel/pango/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
