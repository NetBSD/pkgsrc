# $NetBSD: Makefile,v 1.23 2016/01/06 14:45:01 taca Exp $

DISTNAME=	test-unit-3.1.5
PKGREVISION=	1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/test-unit/test-unit/
COMMENT=	Improved version of Test::Unit
LICENSE=	ruby-license

USE_LANGUAGES=	# none

# ruby23 has the same version.
RUBY_VERSION_SUPPORTED=	200 21 22

.include "../../lang/ruby/rubyversion.mk"

.if ${RUBY_VER} == "200" || ${RUBY_VER} == "21"
DEPENDS+=	${RUBY_PKGPREFIX}-power_assert>=0:../../devel/ruby-power_assert
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
