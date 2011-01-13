# $NetBSD: Makefile,v 1.18 2011/01/13 13:39:14 wiz Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gnomeprint-${VERSION}
COMMENT=		Ruby binding of libgnomeprint
PKGREVISION=		1
CATEGORIES=		print

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gnomeprint-[0-9]*

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
