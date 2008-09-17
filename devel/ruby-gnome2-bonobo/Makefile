# $NetBSD: Makefile,v 1.1 2008/09/17 00:21:48 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-bonobo-${VERSION}
COMMENT=		Ruby binding of libbonobo-2.x or later
CATEGORIES=		devel

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	bonobo

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk
USE_TOOLS+=		pkg-config

.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/libbonobo/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
