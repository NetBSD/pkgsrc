# $NetBSD: Makefile,v 1.31 2013/03/14 13:26:20 obache Exp $

DISTNAME=		rcairo-1.12.4
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		-http://nodeload.github.com/rcairo/rcairo/zip/v${PKGVERSION_NOREV}
EXTRACT_SUFX=		.zip

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

USE_RUBY_EXTCONF=	yes

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../mk/bsd.pkg.mk"
