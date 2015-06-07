# $NetBSD: Makefile,v 1.16 2015/06/07 10:15:23 taca Exp $

DISTNAME=	test-unit-3.1.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

DEPENDS+=	${RUBY_PKGPREFIX}-power_assert>=0:../../devel/ruby-power_assert

USE_LANGUAGES=	# none

RUBY_VERSION_SUPPORTED=	200 21 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
