# $NetBSD: Makefile,v 1.10 2018/09/08 15:56:25 tsutsui Exp $

DISTNAME=		cairo-1.15.14
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://rcairo.github.io/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-native-package-installer>=1.0.3:../../devel/ruby-native-package-installer
DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config>=1.2.2:../../devel/ruby-pkg-config

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
