# $NetBSD: Makefile,v 1.6 2008/06/19 15:11:24 taca Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-glib-[0-9]*

RUBY_EXTCONF_SUBDIRS=	glib

USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
