# $NetBSD: Makefile,v 1.3 2009/10/12 03:09:32 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gstreamer-${VERSION}
COMMENT=		Ruby binding of GStreamer 0.10.x or later
CATEGORIES=		multimedia

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gstreamer

USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/gstreamer/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

BUILDLINK_API_DEPENDS.ruby-gnome2-glib+=	${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}{,nb*}
.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
