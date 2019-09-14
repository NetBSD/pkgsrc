# $NetBSD: Makefile,v 1.1 2019/09/14 18:11:38 tsutsui Exp $
#

DISTNAME=		clutter-gstreamer-${VERSION}
COMMENT=		Ruby binding of Clutter-GStreamer
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-clutter-gstreamer-[0-9]*
SUPERSEDES+=		ruby-gnome2-clutter-gstreamer-[0-9]*

DEPENDS+=	${RUBY_PKGPREFIX}-clutter>=${VERSION}:../../graphics/ruby-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gdk_pixbuf2>=${VERSION}:../../graphics/ruby-gdk_pixbuf2
DEPENDS+=	${RUBY_PKGPREFIX}-gstreamer>=${VERSION}:../../multimedia/ruby-gstreamer
DEPENDS+=	clutter-gst>=3.0:../../multimedia/clutter-gst

.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
