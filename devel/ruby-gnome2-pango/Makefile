# $NetBSD: Makefile,v 1.10 2008/09/17 00:21:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
CATEGORIES=		devel fonts

CONFLICTS+=		ruby-gnome2-pango-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

USE_TOOLS+=		pkg-config

INSTALL_TARGET=		install

do-test:
	${RUN} cd ${WRKSRC}/pango/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
