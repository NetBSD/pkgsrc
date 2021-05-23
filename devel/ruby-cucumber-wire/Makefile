# $NetBSD: Makefile,v 1.9 2021/05/23 09:47:07 taca Exp $

DISTNAME=	cucumber-wire-5.0.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=9.0<10:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-cucumber-expressions>=12.1<13:../../devel/ruby-cucumber-expressions
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=15.0.0:../../devel/ruby-cucumber-messages

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
