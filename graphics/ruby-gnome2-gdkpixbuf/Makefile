# $NetBSD: Makefile,v 1.1.1.1 2006/01/08 03:18:51 minskim Exp $
#

PKGNAME=		ruby-gnome2-gdkpixbuf-${VERSION}
COMMENT=		Ruby binding of GdkPixbuf-2.x
CATEGORIES=		graphics devel

RUBY_EXTCONF_SUBDIRS=	gdkpixbuf

DEPENDS+=		ruby-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
