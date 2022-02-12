# $NetBSD: Makefile,v 1.12 2022/02/12 12:25:18 taca Exp $

DISTNAME=	cucumber-wire-6.2.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=10.1<11:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-cucumber-expressions>=14.0<15:../../devel/ruby-cucumber-expressions
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=17.1<18:../../devel/ruby-cucumber-messages

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
