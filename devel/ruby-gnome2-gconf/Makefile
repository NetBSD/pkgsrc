# $NetBSD: Makefile,v 1.2 2010/09/23 15:35:59 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gconf-${VERSION}
COMMENT=		Ruby binding of GConf-1.2.x or later
CATEGORIES=		devel

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gconf

do-test:
	${RUN} cd ${WRKSRC}/gconf/tests; \
		${SETENV} ${TEST_ENV} ${RUBY} -I ${WRKSRC}/gconf/src unittest.rb

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
