# $NetBSD: Makefile,v 1.13 2012/03/03 00:13:41 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gstreamer-${VERSION}
COMMENT=		Ruby binding of GStreamer 0.10.x or later
PKGREVISION=		2
CATEGORIES=		multimedia

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gstreamer-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gstreamer

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

do-test:
	${RUN} cd ${WRKSRC}/gstreamer/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../multimedia/gstreamer0.10/buildlink3.mk"
.include "../../multimedia/gst-plugins0.10-base/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
