# $NetBSD: Makefile,v 1.12 2013/02/07 13:41:55 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gio-${VERSION}
COMMENT=		Ruby binding of gio-2.0.x
CATEGORIES=		devel

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gio-[0-9]*

RUBY_EXTCONF_SUBDIRS=	gio2

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

do-test:
	${RUN} cd ${WRKSRC}/gio2/test && ${SETENV} ${TEST_ENV} ${RUBY} load-test.rb

.include "../../devel/glib2/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
