# $NetBSD: Makefile,v 1.10 2012/09/15 10:04:21 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gio-${VERSION}
COMMENT=		Ruby binding of gio-2.0.x
PKGREVISION=		1
CATEGORIES=		devel

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gio-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gio2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

do-test:
	${RUN} cd ${WRKSRC}/gio2/test && ${SETENV} ${TEST_ENV} ${RUBY} load-test.rb

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
