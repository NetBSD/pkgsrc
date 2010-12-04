# $NetBSD: Makefile,v 1.5 2010/12/04 03:45:23 taca Exp $

DISTNAME=	pg-0.10.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/postgres/&ql/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ged/ruby-pg/
COMMENT=	Ruby extension for PostgreSQL
LICENSE=	gnu-gpl-v2 OR ruby-license

GEM_CLEANBUILD=	.require_paths ext/*
CONFIGURE_ARGS=	--with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		--with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

.include "../../lang/ruby/gem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
