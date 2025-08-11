# $NetBSD: Makefile,v 1.47 2025/08/11 14:29:40 taca Exp $

DISTNAME=	pg-1.6.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/postgres/&ql/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://github.com/ged/ruby-pg
COMMENT=	Ruby extension for PostgreSQL
LICENSE=	2-clause-bsd OR ruby-license

CONFIGURE_ARGS=	--with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		--with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
