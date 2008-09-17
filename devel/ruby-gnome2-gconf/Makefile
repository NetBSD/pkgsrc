# $NetBSD: Makefile,v 1.1 2008/09/17 00:21:49 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gconf-${VERSION}
COMMENT=		Ruby binding of GConf-1.2.x or later
CATEGORIES=		devel

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gconf

USE_TOOLS+=		pkg-config

do-test:
	${RUN} cd ${WRKSRC}/gconf/tests; \
		${SETENV} ${TEST_ENV} ${RUBY} -I ${WRKSRC}/gconf/src unittest.rb

.include "../../devel/GConf/buildlink3.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
