# $NetBSD: Makefile,v 1.14 2026/02/03 15:05:45 taca Exp $

DISTNAME=	cucumber-wire-8.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=11<16:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-cucumber-expressions>=14.0<20:../../devel/ruby-cucumber-expressions

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
