# $NetBSD: Makefile,v 1.7 2020/04/27 05:09:02 taca Exp $

DISTNAME=	cucumber-wire-3.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=7.0.0:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-cucumber-expressions>=10.1.0:../../devel/ruby-cucumber-expressions
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=12.1<13:../../devel/ruby-cucumber-messages

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
