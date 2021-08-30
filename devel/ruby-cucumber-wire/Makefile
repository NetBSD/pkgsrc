# $NetBSD: Makefile,v 1.10 2021/08/30 16:33:29 taca Exp $

DISTNAME=	cucumber-wire-6.1.1
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=10.0<11:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-cucumber-expressions>=12.1<13:../../devel/ruby-cucumber-expressions
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-messages>=17.0<18:../../devel/ruby-cucumber-messages

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
