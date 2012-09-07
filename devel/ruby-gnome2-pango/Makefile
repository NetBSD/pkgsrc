# $NetBSD: Makefile,v 1.27 2012/09/07 19:16:28 adam Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-pango-${VERSION}
COMMENT=		Ruby binding of pango-1.x
PKGREVISION=		1
CATEGORIES=		devel fonts

CONFLICTS+=		ruby-gnome2-pango-[0-9]*
CONFLICTS+=		ruby[0-9][0-9]-gnome2-pango-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	pango

DEPENDS+=		${RUBY_PKGPREFIX}-gnome2-glib>=${VERSION}:../../devel/ruby-gnome2-glib

do-test:
	${RUN} cd ${WRKSRC}/pango/test; ${SETENV} ${TEST_ENV} ${RUBY} run-test.rb

.include "../../devel/pango/buildlink3.mk"
.include "../../graphics/ruby-rcairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
