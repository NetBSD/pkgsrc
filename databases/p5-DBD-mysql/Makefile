# $NetBSD: Makefile,v 1.1.1.1 1999/06/10 18:32:36 bad Exp $
#

DISTNAME=	Msql-Mysql-modules-1.2017
PKGNAME=	p5-DBD-mysql-1.2017
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com.org/

DEPENDS+=	mysql-client-3.22.22:../../databases/mysql-client
DEPENDS+=	p5-DBI-1.08:../../databases/p5-DBI
DEPENDS+=	p5-Data-Dumper-2.10:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Data-ShowTable-3.3:../../devel/p5-Data-ShowTable

USE_PERL5=	YES

MYSQL_HEADERDIR=	${LOCALBASE}/include/mysql
MYSQL_LIBDIR=	${LOCALBASE}/lib/mysql

CONFIGURE_ENV+=	MYSQL_HEADERDIR="${MYSQL_HEADERDIR}"
CONFIGURE_ENV+=	MYSQL_LIBDIR="${MYSQL_LIBDIR}"
CONFIGURE_ENV+=	IN_MYSQL_DISTRIBUTION=1

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${LOCALBASE}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
