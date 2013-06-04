# $NetBSD: Makefile,v 1.24 2013/06/04 22:16:26 tron Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-clutter-core-${VERSION}
COMMENT=		Ruby binding for Clutter Core library
PKGREVISION=		19
CATEGORIES=		graphics

RUBY_EXTCONF_SUBDIRS=	clutter
RUBY_VERSION_SUPPORTED= 18

USE_TOOLS+=		pkg-config

.include "../../devel/ruby-gnome2-glib/buildlink3.mk"
.include "../../devel/glib2/buildlink3.mk"
.include "../../graphics/clutter08/buildlink3.mk"
.include "../../graphics/ruby-clutter/Makefile.common"
