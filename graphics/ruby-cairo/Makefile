# $NetBSD: Makefile,v 1.17 2021/03/07 14:47:07 taca Exp $

DISTNAME=		cairo-1.17.5
CATEGORIES=		graphics

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://rcairo.github.io/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-native-package-installer>=1.0.3:../../devel/ruby-native-package-installer
DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config>=1.2.2:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-red-colors>=0.1:../../devel/ruby-red-colors

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
