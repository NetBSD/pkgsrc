# $NetBSD: Makefile,v 1.7 2018/03/14 14:35:06 taca Exp $

DISTNAME=		cairo-1.15.11
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://rcairo.github.io/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

DEPENDS+=		${RUBY_PKGPREFIX}-native-package-installer>=0:../../devel/ruby-native-package-installer
OVERRIDE_GEMSPEC+=	native-package-installer:

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
