# $NetBSD: Makefile,v 1.16 2002/06/16 22:03:03 wiz Exp $
#

DISTNAME=		Msql-Mysql-modules-1.2219
PKGNAME=		p5-DBD-mysql-1.2219
SVR4_PKGNAME=		p5dmy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		bad@netbsd.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		Perl DBI/DBD driver for MySQL databases

DEPENDS+=		p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=		p5-Data-ShowTable-3.3:../../devel/p5-Data-ShowTable

BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.23.49nb1

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Msql-Mysql-modules/.packlist

MYSQL_HEADERDIR=	${PREFIX}/include/mysql
MYSQL_LIBDIR=		${PREFIX}/lib/mysql

MAKE_ENV+=		MYSQL_HEADERDIR="${MYSQL_HEADERDIR}"
MAKE_ENV+=		MYSQL_LIBDIR="${MYSQL_LIBDIR}"
MAKE_ENV+=		IN_MYSQL_DISTRIBUTION=1

MAKE_PARAMS+=		--noprompt
MAKE_PARAMS+=		--mysql-install
MAKE_PARAMS+=		--nomsql-install --nomsql1-install
MAKE_PARAMS+=		--mysql-incdir=${MYSQL_HEADERDIR}
MAKE_PARAMS+=		--mysql-libdir=${MYSQL_LIBDIR}

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL ${MAKE_PARAMS}

.include "../../databases/mysql-client/buildlink.mk"
.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
