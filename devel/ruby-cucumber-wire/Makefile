# $NetBSD: Makefile,v 1.3 2019/01/20 13:44:24 taca Exp $

DISTNAME=	cucumber-wire-1.0.0
CATEGORIES=	devel

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://cucumber.io/
COMMENT=	Wire protocol for Cucumber
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-core>=4.0<5:../../devel/ruby-cucumber-core
DEPENDS+=	${RUBY_PKGPREFIX}-cucumber-expressions>=6.0<7:../../devel/ruby-cucumber-expressions

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
