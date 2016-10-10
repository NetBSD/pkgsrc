# $NetBSD: Makefile,v 1.2 2016/10/10 14:59:23 taca Exp $

DISTNAME=		cairo-1.15.2
CATEGORIES=		graphics

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://rcairo.github.io/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
