# $NetBSD: Makefile,v 1.4 2007/01/29 06:42:34 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-glib-[0-9]*

RUBY_EXTCONF_SUBDIRS=	glib

USE_TOOLS+=		pkg-config

.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
