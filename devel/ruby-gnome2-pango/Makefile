# $NetBSD: Makefile,v 1.2 2006/01/24 07:32:04 wiz Exp $
#

PKGNAME=		ruby-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
PKGREVISION=		1
CATEGORIES=		devel fonts

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

USE_TOOLS+=		pkg-config

INSTALL_TARGET=		install

.include "../../devel/pango/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
