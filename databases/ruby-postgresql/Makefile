# $NetBSD: Makefile,v 1.2 2001/07/08 17:36:10 mjl Exp $

DISTNAME=	ruby-postgres-0.6.4
PKGNAME=	${RUBY_PKGNAMEPREFIX}postgresql-0.6.4
CATEGORIES=	databases
MASTER_SITES=	http://www.jp.postgresql.org/interfaces/ruby/archive/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.jp.postgresql.org/interfaces/ruby/
COMMENT=	Ruby extension for postgresql

DEPENDS+=	postgresql-lib>=7.1:../../databases/postgresql-lib

USE_RUBY_EXTCONF= yes
CONFIGURE_ARGS+=--with-pgsql-include-dir=${PREFIX}/include/pgsql \
		--with-pgsql-lib-dir=${PREFIX}/lib

do-install:
	${INSTALL_DATA} ${WRKSRC}/postgres.so ${RUBY_SITEARCHLIBDIR}/postgres.so

.include "../../lang/ruby-base/Makefile.common"
.include "../../mk/bsd.pkg.mk"
