# $NetBSD: Makefile,v 1.15 2015/03/02 11:05:34 joerg Exp $

DISTNAME=	test-unit-3.0.9
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-power_assert>=0:../../devel/ruby-power_assert
RUBY_VERSION_SUPPORTED=	200 21

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
