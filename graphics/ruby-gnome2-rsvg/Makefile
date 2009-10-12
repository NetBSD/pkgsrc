# $NetBSD: Makefile,v 1.12 2009/10/12 03:09:32 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-rsvg-${VERSION}
COMMENT=		Ruby binding of librsvg
CATEGORIES=		graphics

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	rsvg

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
USE_TOOLS+=		pkg-config

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
