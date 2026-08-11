# $NetBSD: Makefile,v 1.2 2026/08/11 15:42:54 taca Exp $

DISTNAME=	with_advisory_lock-7.6.0
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ClosureTree/with_advisory_lock
COMMENT=	Advisory locking for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}

RUBY_VERSIONS_ACCEPTED=	33 34

#
# This pacakge is for redmine60 and redmine61
#
RUBY_RAILS_ACCEPTED=	72

USE_LANGUAGES=	# none

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
