# $NetBSD: Makefile,v 1.2 2020/01/16 15:17:32 taca Exp $

DISTNAME=	postgres_ext-3.0.1
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/dockyard/postgres_ext
COMMENT=	Native PostgreSQL data types for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_ACTIVERECORD_DEPENDS}
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=4.0.1:../../databases/ruby-arel
DEPENDS+=	${RUBY_PKGPREFIX}-pg_array_parser>=0.0.9:../../databases/ruby-pg_array_parser

USE_LANGUAGES=	# none

RUBY_RAILS_ACCEPTED=	42

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
