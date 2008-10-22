# $NetBSD: Makefile,v 1.8 2008/10/22 10:42:03 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-glib-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	glib

USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/glib/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb


.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
