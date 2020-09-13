# $NetBSD: Makefile,v 1.8 2020/09/13 15:41:16 taca Exp $

DISTNAME=	cucumber-wire-4.0.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=8.0<9:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-cucumber-expressions>=10.3.0:../../devel/ruby-cucumber-expressions
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=13.0<14:../../devel/ruby-cucumber-messages

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
