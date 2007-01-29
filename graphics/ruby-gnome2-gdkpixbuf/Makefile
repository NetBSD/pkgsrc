# $NetBSD: Makefile,v 1.6 2007/01/29 06:42:34 minskim Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf-${VERSION}
COMMENT=		Ruby binding of GdkPixbuf-2.x
CATEGORIES=		graphics devel

CONFLICTS+=		ruby-gnome2-gdkpixbuf-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gdkpixbuf

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.gtk2+=	gtk2+>=2.6.0
.include "../../x11/gtk2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
