# $NetBSD: Makefile,v 1.2 2007/06/09 01:07:13 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprint-${VERSION}
COMMENT=		Ruby binding of libgnomeprint
CATEGORIES=		print

RUBY_EXTCONF_SUBDIRS=	gnomeprint

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
USE_TOOLS+=		pkg-config

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
