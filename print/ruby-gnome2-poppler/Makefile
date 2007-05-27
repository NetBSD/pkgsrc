# $NetBSD: Makefile,v 1.1.1.1 2007/05/27 02:00:02 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-poppler-${VERSION}
COMMENT=		Ruby binding of poppler-glib
CATEGORIES=		print

RUBY_EXTCONF_SUBDIRS=	poppler

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-gdkpixbuf>=${VERSION}:../../graphics/ruby-gnome2-gdkpixbuf
USE_TOOLS+=		pkg-config

BUILDLINK_API_DEPENDS.poppler-glib+=	poppler-glib>=0.5.2

.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../print/poppler-glib/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
