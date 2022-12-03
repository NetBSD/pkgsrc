# $NetBSD: Makefile,v 1.25 2022/12/03 06:36:49 taca Exp $

DISTNAME=	power_assert-2.0.2
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
