# $NetBSD: Makefile,v 1.2 2009/10/17 09:24:13 taca Exp $

DISTNAME=	pg-0.8.0
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/postgres/&ql/}
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-pg/
COMMENT=	Ruby extension for PostgreSQL
LICENSE=	gnu-gpl-v2

GEM_BUILD=	gemspec
CONFIGURE_ARGS=	--with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		--with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
