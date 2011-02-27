# $NetBSD: Makefile,v 1.10.2.1 2011/02/27 00:26:21 tron Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gtkglext-${VERSION}
COMMENT=		Ruby binding of gtkglext
PKGREVISION=		1
CATEGORIES=		graphics

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gtkglext-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gtkglext

DEPENDS+=		${RUBY_PKGPREFIX}-opengl-[0-9]*:../../graphics/ruby-opengl
DEPENDS+=               ${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../graphics/gtkglext/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
