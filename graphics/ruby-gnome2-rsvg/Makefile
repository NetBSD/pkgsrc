# $NetBSD: Makefile,v 1.4 2007/09/19 23:18:58 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-rsvg-${VERSION}
COMMENT=		Ruby binding of librsvg
PKGREVISION=		3
CATEGORIES=		graphics

RUBY_EXTCONF_SUBDIRS=	rsvg

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
USE_TOOLS+=		pkg-config

.include "../../graphics/librsvg2/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
