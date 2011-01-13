# $NetBSD: Makefile,v 1.20 2011/01/13 13:38:19 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomecanvas-${VERSION}
COMMENT=		Ruby binding of GnomeCanvas-2.x
PKGREVISION=		1
CATEGORIES=		graphics gnome

CONFLICTS+=		ruby-gnome2-gnomecanvas-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-gnomecanvas-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomecanvas

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/libgnomecanvas/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
