# $NetBSD: Makefile,v 1.36 2012/10/02 17:11:18 tron Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-rsvg-${VERSION}
COMMENT=		Ruby binding of librsvg
PKGREVISION=		3
CATEGORIES=		graphics

CONFLICTS+=		ruby[0-9][0-9]-gnome2-rsvg-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	rsvg2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
