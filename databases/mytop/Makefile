# $NetBSD: Makefile,v 1.2 2001/07/08 13:07:45 zuntum Exp $
#

DISTNAME=	mytop-0.8
CATEGORIES=	databases
MASTER_SITES=	http://public.yahoo.com/~jzawodn/mytop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://public.yahoo.com/~jzawodn/mytop/
COMMENT=	console-based tool for monitoring the threads and performance of MySQL

DEPENDS+=	p5-DBI-*:../../databases/p5-DBI
DEPENDS+=	p5-Term-ReadKey-*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBD-mysql-*:../../databases/p5-DBD-mysql

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/mytop/.packlist
REPLACE_PERL=	mytop
NO_BUILD=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
