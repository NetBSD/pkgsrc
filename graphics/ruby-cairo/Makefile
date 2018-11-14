# $NetBSD: Makefile,v 1.12 2018/11/14 22:21:45 kleink Exp $

DISTNAME=		cairo-1.16.2
PKGREVISION=		1
CATEGORIES=		graphics

MAINTAINER=		tsutsui@NetBSD.org
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
