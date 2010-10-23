# $NetBSD: Makefile,v 1.3 2010/10/23 12:45:08 obache Exp $
#

PKGNAME=		${RUBY_PKGPREFIX}-gnome2-gconf-${VERSION}
COMMENT=		Ruby binding of GConf-1.2.x or later
CATEGORIES=		devel

CONFLICTS+=		ruby[0-9][0-9]-gnome2-gconf-[0-9]*

PKG_DESTDIR_SUPPORT=	user-destdir

RUBY_EXTCONF_SUBDIRS=	gconf

do-test:
	${RUN} cd ${WRKSRC}/gconf/tests; \
		${SETENV} ${TEST_ENV} ${RUBY} -I ${WRKSRC}/gconf/src unittest.rb

.include "../../devel/GConf/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../meta-pkgs/ruby-gnome2/Makefile.common"
