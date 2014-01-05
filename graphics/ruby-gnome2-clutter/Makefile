# $NetBSD: Makefile,v 1.1 2014/01/05 09:04:31 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-clutter-${VERSION}
COMMENT=		Ruby binding of Clutter
CATEGORIES=		graphics

DEPENDS+=	${RUBY_PKGPREFIX}-gnome2-gobject-introspection>=${VERSION}:../../devel/ruby-gnome2-gobject-introspection
DEPENDS+=	clutter>=1.0:../../graphics/clutter

RUBY_SETUP_SUBDIRS=	clutter

USE_RUBY_EXTCONF=	no
USE_RUBY_SETUP=		yes
USE_RUBY_SETUP_PKG=	yes

do-test:
	${RUN} cd ${WRKSRC}/clutter/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
