# $NetBSD: Makefile,v 1.15 2010/08/27 05:15:33 obache Exp $

DISTNAME=		rcairo-1.8.4
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config

USE_RUBY_EXTCONF=	yes
RUBY_HAS_ARCHILIB=	yes

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../mk/bsd.pkg.mk"
