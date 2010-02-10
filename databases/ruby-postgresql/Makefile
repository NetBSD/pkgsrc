# $NetBSD: Makefile,v 1.35 2010/02/10 19:34:06 joerg Exp $

DISTNAME=	postgres-0.7.9.2008.01.28
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/postgres/&ql/}
PKGREVISION=	1
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://rubyforge.org/projects/ruby-pg/
COMMENT=	Ruby extension for PostgreSQL

GEM_BUILD=	gemspec
CONFIGURE_ARGS=	--with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		--with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

.include "../../misc/rubygems/rubygem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
