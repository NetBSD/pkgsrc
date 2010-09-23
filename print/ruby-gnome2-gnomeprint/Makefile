# $NetBSD: Makefile,v 1.14 2010/09/23 15:36:02 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprint-${VERSION}
COMMENT=		Ruby binding of libgnomeprint
CATEGORIES=		print

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gnomeprint

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-libart>=${VERSION}:../../graphics/ruby-gnome2-libart

do-test:
	${RUN} cd ${WRKSRC}/gnomeprint/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../print/libgnomeprint/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
