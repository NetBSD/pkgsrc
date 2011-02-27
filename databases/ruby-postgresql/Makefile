# $NetBSD: Makefile,v 1.36.4.1 2011/02/27 00:26:14 tron Exp $

DISTNAME=	postgres-0.7.9.2008.01.28
PKGNAME=	${RUBY_PKGPREFIX}-${DISTNAME:C/postgres/&ql/}
PKGREVISION=	2
CATEGORIES=	databases

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://bitbucket.org/ged/ruby-pg/
COMMENT=	Ruby extension for PostgreSQL
LICENSE=	gnu-gpl-v2 OR ruby-license

CONFIGURE_ARGS=	--with-pgsql-include-dir=${PGSQL_PREFIX}/include/postgresql \
		--with-pgsql-lib-dir=${PGSQL_PREFIX}/lib

pre-configure:
	chmod -R g-w ${WRKSRC}

.include "../../lang/ruby/gem.mk"
.include "../../mk/pgsql.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
