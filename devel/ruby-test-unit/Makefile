# $NetBSD: Makefile,v 1.20.2.1 2016/01/18 21:05:16 bsiegert Exp $

DISTNAME=	test-unit-3.1.5
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} != "23"
DEPENDS+=	${RUBY_PKGPREFIX}-power_assert>=0:../../devel/ruby-power_assert
.endif

RUBY_VERSION_SUPPORTED=	200 21 22

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
