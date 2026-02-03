# $NetBSD: Makefile,v 1.1 2026/02/03 14:45:13 taca Exp $

DISTNAME=	with_advisory_lock-7.5.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ClosureTree/with_advisory_lock
COMMENT=	Advisory locking for ActiveRecord
LICENSE=	mit

#DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_RAILTIES_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-zeitwerk>=2.7:../../devel/ruby-zeitwerk

RUBY_VERSIONS_ACCEPTED=	33 34

#
# This pacakge is for redmine60 and redmine61
#
RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
