# $NetBSD: Makefile,v 1.5 2020/03/15 17:34:44 taca Exp $

DISTNAME=	cucumber-wire-2.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=6.0.0<7:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-expressions>=8.0.2<9:../../devel/ruby-cucumber-expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
