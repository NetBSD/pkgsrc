# $NetBSD: Makefile,v 1.1 2014/01/05 09:06:05 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-clutter-gtk-${VERSION}
COMMENT=		Ruby binding of Clutter-GTK
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-clutter>=${VERSION}:../../graphics/ruby-gnome2-clutter
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gtk3>=${VERSION}:../../x11/ruby-gnome2-gtk3
DEPENDS+=	clutter-gtk>=1.0:../../graphics/clutter-gtk

RUBY_SETUP_SUBDIRS=	clutter-gtk

USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/clutter-gtk/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
