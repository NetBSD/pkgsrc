# $NetBSD: Makefile,v 1.20 2013/05/08 12:47:05 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gstreamer-${VERSION}
COMMENT=		Ruby binding of GStreamer 1.0.x or later
CATEGORIES=		multimedia

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gstreamer-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gstreamer

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base

.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
