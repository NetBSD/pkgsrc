# $NetBSD: Makefile,v 1.26 2012/09/07 19:16:53 adam Exp $

DISTNAME=		rcairo-1.10.2
PKGNAME=		${RUBY_PKGPREFIX}-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		graphics
MASTER_SITES=		http://cairographics.org/releases/

MAINTAINER=		obache@NetBSD.org
HOMEPAGE=		http://cairographics.org/rcairo/
COMMENT=		Ruby bindings for cairo
LICENSE=		ruby-license OR gnu-gpl-v2

PKG_DESTDIR_SUPPORT=	user-destdir

USE_TOOLS+=		pkg-config

USE_RUBY_EXTCONF=	yes

#do-test:
#	${RUN} cd ${WRKSRC}; \
#	${SETENV} ${TEST_ENV} ${RUBY} test/run-test.rb

BUILDLINK_API_DEPENDS.cairo+=	cairo>=1.2.0
.include "../../graphics/cairo/buildlink3.mk"
.include "../../lang/ruby/modules.mk"
.include "../../devel/ruby-pkg-config/tool.mk"
.include "../../mk/bsd.pkg.mk"
