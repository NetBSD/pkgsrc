# $NetBSD: Makefile,v 1.2 2020/03/08 16:50:47 wiz Exp $
#

DISTNAME=		gstreamer-${VERSION}
COMMENT=		Ruby binding of GStreamer 1.0.x or later
PKGREVISION=		1
CATEGORIES=		multimedia

MAINTAINER=		pkgsrc-users@NetBSD.org

CONFLICTS+=		ruby-gnome2-gstreamer-[0-9]*
SUPERSEDES+=		ruby-gnome2-gstreamer-[0-9]*

DEPENDS+=		${RUBY_PKGPREFIX}-gobject-introspection>=${VERSION}:../../devel/ruby-gobject-introspection
DEPENDS+=		gst-plugins1-base-[0-9]*:../../multimedia/gst-plugins1-base

.include "../../devel/ruby-gobject-introspection/buildlink3.mk"
.include "../../multimedia/gstreamer1/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome/Makefile.common"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
