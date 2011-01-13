# $NetBSD: Makefile,v 1.16 2011/01/13 13:38:19 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-libart-${VERSION}
COMMENT=		Ruby binding of Libart_lgpl
PKGREVISION=		1
CATEGORIES=		graphics

CONFLICTS+=		ruby-gnome2-libart-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-libart-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	libart

BUILD_DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

.include "../../mk/jpeg.buildlink3.mk"
.include "../../graphics/png/buildlink3.mk"
.include "../../graphics/libart/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
