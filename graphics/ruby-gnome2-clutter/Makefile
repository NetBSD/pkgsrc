# $NetBSD: Makefile,v 1.2 2014/12/30 08:53:44 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-clutter-${VERSION}
COMMENT=		Ruby binding of Clutter
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-pango>=${VERSION}:../../devel/ruby-gnome2-pango
DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-cairo-gobject>=${VERSION}:../../graphics/ruby-gnome2-cairo-gobject
DEPENDS+=	clutter>=1.0:../../graphics/clutter

RUBY_SETUP_SUBDIRS=	clutter

USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/clutter/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
