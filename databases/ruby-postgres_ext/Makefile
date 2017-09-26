# $NetBSD: Makefile,v 1.1 2017/09/26 16:25:55 minskim Exp $

DISTNAME=	postgres_ext-3.0.0
CATEGORIES=	databases

MAINTAINER=	minskim@NetBSD.org
HOMEPAGE=	https://github.com/dockyard/postgres_ext
COMMENT=	Native PostgreSQL data types for ActiveRecord
LICENSE=	mit

DEPENDS+=	${RUBY_PKGPREFIX}-activerecord42>=4.0.0:../../databases/ruby-activerecord42
DEPENDS+=	${RUBY_PKGPREFIX}-arel>=4.0.1:../../databases/ruby-arel
DEPENDS+=	${RUBY_PKGPREFIX}-pg_array_parser>=0.0.9:../../databases/ruby-pg_array_parser

.include "../../lang/ruby/gem.mk"
.include "../../mk/bsd.pkg.mk"
