# $NetBSD: Makefile,v 1.1 2014/01/05 09:15:59 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-clutter-gstreamer-${VERSION}
COMMENT=		Ruby binding of Clutter-GStreamer
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter>=${VERSION}:../../graphics/ruby-gnome2-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gstreamer>=${VERSION}:../../multimedia/ruby-gnome2-gstreamer
DEPENDS+=	clutter-gst>=2.0:../../multimedia/clutter-gst

RUBY_SETUP_SUBDIRS=	clutter-gstreamer

USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/clutter-gstreamer/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
