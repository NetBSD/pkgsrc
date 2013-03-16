# $NetBSD: Makefile,v 1.41 2013/03/16 12:25:48 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-rsvg-${VERSION}
COMMENT=		Ruby binding of librsvg
CATEGORIES=		graphics

CONFLICTS+=		ruby[0-9][0-9]-gnome2-rsvg-[0-9]*

RUBY_EXTCONF_SUBDIRS=	rsvg2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf

.include "../../graphics/librsvg/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
