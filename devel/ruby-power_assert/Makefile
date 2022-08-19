# $NetBSD: Makefile,v 1.24 2022/08/19 14:16:47 tnn Exp $

DISTNAME=	power_assert-2.0.1
CATEGORIES=	devel

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ruby/power_assert
COMMENT=	Power Assert for Ruby
LICENSE=	2-clause-bsd

USE_LANGUAGES=	# none

.include "../../lang/ruby/rubyversion.mk"

.if "power_assert-${RUBY_POWER_ASSERT_VER}" == ${DISTNAME}
PKG_SKIP_REASON+=	"${DISTNAME} is included in ${RUBY_BASE}"
.endif

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
