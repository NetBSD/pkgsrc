# $NetBSD: Makefile,v 1.6 2018/03/12 11:15:37 wiz Exp $

DISTNAME=		cairo-1.15.9
PKGREVISION=		1
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
