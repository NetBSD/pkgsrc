# $NetBSD: Makefile,v 1.23 2016/01/24 05:03:24 tsutsui Exp $
#

DISTNAME=		gstreamer-${VERSION}
PKGNAME=		${RUBY_PKGPREFIX}-gnome2-${DISTNAME}
PKGREVISION=		1
COMMENT=		Ruby binding of GStreamer 1.0.x or later
CATEGORIES=		multimedia

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gstreamer-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=		gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/gobject-introspection/buildlink3.mk"
.include "../../devel/ruby-gnome2-gobject-introspection/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
