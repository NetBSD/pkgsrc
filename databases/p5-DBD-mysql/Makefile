# $NetBSD: Makefile,v 1.6 2000/05/25 08:08:30 rh Exp $
#

DISTNAME=	Msql-Mysql-modules-1.2214
PKGNAME=	p5-DBD-mysql-1.2214
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.mysql.com.org/

DEPENDS+=	mysql-client-3.22.32:../../databases/mysql-client
DEPENDS+=	p5-DBI-1.13:../../databases/p5-DBI
DEPENDS+=	p5-Data-Dumper>=2.101:../../devel/p5-Data-Dumper
DEPENDS+=	p5-Data-ShowTable-3.3:../../devel/p5-Data-ShowTable

USE_PERL5=	YES

MYSQL_HEADERDIR= ${PREFIX}/include/mysql
MYSQL_LIBDIR=	${PREFIX}/lib/mysql

CONFIGURE_ENV+=	MYSQL_HEADERDIR="${MYSQL_HEADERDIR}"
CONFIGURE_ENV+=	MYSQL_LIBDIR="${MYSQL_LIBDIR}"
CONFIGURE_ENV+=	IN_MYSQL_DISTRIBUTION=1

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL --noprompt --mysql-install --nomsql-install --nomsql1-install --mysql-incdir=${MYSQL_HEADERDIR} --mysql-libdir=${MYSQL_LIBDIR}

.include "../../mk/bsd.pkg.mk"
