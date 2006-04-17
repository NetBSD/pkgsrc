# $NetBSD: Makefile,v 1.4 2006/04/17 13:46:21 wiz Exp $
#

PKGNAME=		ruby-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
PKGREVISION=		3
CATEGORIES=		devel fonts

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

USE_TOOLS+=		pkg-config

INSTALL_TARGET=		install

.include "../../devel/pango/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
