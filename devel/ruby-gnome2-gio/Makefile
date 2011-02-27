# $NetBSD: Makefile,v 1.1.2.1 2011/02/27 00:26:16 tron Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gio-${VERSION}
PKGREVISION=		1
COMMENT=		Ruby binding of gio-2.0.x
PKGREVISION=		1
CATEGORIES=		devel

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gio-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gio2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
