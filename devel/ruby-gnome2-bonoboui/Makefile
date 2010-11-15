# $NetBSD: Makefile,v 1.10 2010/11/15 22:56:47 abs Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-bonoboui-${VERSION}
COMMENT=		Ruby binding of libbonoboui-2.x or later
PKGREVISION=		1
CATEGORIES=		devel

CONFLICTS+=		ruby[0-9][0-9]-gnome2-bonoboui-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	bonoboui

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gnome>=${VERSION}:../../x11/ruby-gnome2-gnome
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gtk>=${VERSION}:../../x11/ruby-gnome2-gtk

.include "../../x11/gtk2/buildlink3.mk"
BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
BUILDLINK_DEPMETHOD.ruby-gnome2-glib=	build
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/libbonoboui/buildlink3.mk"
.include "../../devel/libgnomeui/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
