# $NetBSD: Makefile,v 1.7 2008/09/17 00:21:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-glib-${VERSION}
COMMENT=		Ruby binding of GLib-2.x
CATEGORIES=		devel

CONFLICTS+=		ruby-gnome2-glib-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	glib

USE_TOOLS+=		pkg-config

# Need glib-enum-types.h for build ruby-gnome2-{gtk,gnomecanvas}.
post-install:
	${INSTALL_DATA} ${WRKSRC}/glib/src/glib-enum-types.h \
		${DESTDIR}${RUBY_VENDORARCHLIBDIR}

do-test:
	${RUN} cd ${WRKSRC}/glib/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb


.include "../../devel/glib2/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
