# $NetBSD: Makefile,v 1.30 2026/04/08 15:10:40 tsutsui Exp $

DISTNAME=		cairo-1.18.5
CATEGORIES=		graphics

MAINTAINER=		tsutsui@NetBSD.org
HOMEPAGE=		https://rcairo.github.io/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

DEPENDS+=	${RUBY_PKGPREFIX}-pkg-config>=1.2.2:../../devel/ruby-pkg-config
DEPENDS+=	${RUBY_PKGPREFIX}-red-colors>=0.1:../../devel/ruby-red-colors

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0

.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
BUILDLINK_API_DEPENDS.freetype2= freetype2>=2.10.4
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
