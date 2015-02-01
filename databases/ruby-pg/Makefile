# $NetBSD: Makefile,v 1.20 2015/02/01 13:24:46 taca Exp $

DISTNAME=	pg-0.18.1
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/postgres/&ql/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ged/ruby-pg/
COMMENT=	Ruby extension for PostgreSQL
LICENSE=	2-clause-bsd OR ruby-license

RUBY_RDOC_REQD=	2.5.8
CONFIGURE_ARGS=	--with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		--with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
