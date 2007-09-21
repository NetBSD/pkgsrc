# $NetBSD: Makefile,v 1.3 2007/09/21 13:04:15 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprint-${VERSION}
COMMENT=		Ruby binding of libgnomeprint
PKGREVISION=		1
CATEGORIES=		print

RUBY_EXTCONF_SUBDIRS=	gnomeprint

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
USE_TOOLS+=		pkg-config

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
