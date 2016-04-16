# $NetBSD: Makefile,v 1.3 2016/04/16 17:41:04 tsutsui Exp $
#

DISTNAME=		clutter-gstreamer-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
COMMENT=		Ruby binding of Clutter-GStreamer
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter>=${VERSION}:../../graphics/ruby-gnome2-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gstreamer>=${VERSION}:../../multimedia/ruby-gnome2-gstreamer
DEPENDS+=	clutter-gst>=2.0:../../multimedia/clutter-gst

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
