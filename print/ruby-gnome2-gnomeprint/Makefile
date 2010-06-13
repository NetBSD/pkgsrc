# $NetBSD: Makefile,v 1.12 2010/06/13 22:45:17 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprint-${VERSION}
COMMENT=		Ruby binding of libgnomeprint
PKGREVISION=		3
CATEGORIES=		print

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomeprint

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart
USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/gnomeprint/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
