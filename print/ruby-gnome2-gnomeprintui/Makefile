# $NetBSD: Makefile,v 1.13 2011/01/13 13:39:14 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprintui-${VERSION}
COMMENT=		Ruby binding of libgnomeprintui
PKGREVISION=		1
CATEGORIES=		print

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gnomeprintui-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomeprintui

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnomeprint>=${VERSION}:../../print/ruby-gnome2-gnomeprint
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../print/libgnomeprintui/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-gnomeprint+=	${RUBY_PKGPREFIX}-gnome2-gnomeprint>=${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-gnomeprint=	build
.include "../../print/ruby-gnome2-gnomeprint/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
