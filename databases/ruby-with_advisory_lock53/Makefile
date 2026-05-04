# $NetBSD: Makefile,v 1.3 2026/05/04 06:11:46 taca Exp $

DISTNAME=	with_advisory_lock-5.3.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:S/-/53-/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ClosureTree/with_advisory_lock
COMMENT=	Advisory locking for ActiveRecord
LICENSE=	mit

RUBY_VERSIONS_ACCEPTED=	33 34

# This pacakge is assumed to used by redmine51, redmine60 and redmine61.
# To shared by multiple rails, omit dependency here.
#DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
#
#RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
