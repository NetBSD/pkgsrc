# $NetBSD: Makefile,v 1.4 2002/10/27 23:23:34 seb Exp $
#

DISTNAME=	mytop-0.8
CATEGORIES=	databases
MASTER_SITES=	http://public.yahoo.com/~jzawodn/mytop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://public.yahoo.com/~jzawodn/mytop/
COMMENT=	console-based tool for monitoring the threads and performance of MySQL

DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI
DEPENDS+=	p5-Term-ReadKey-[0-9]*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBD-mysql-[0-9]*:../../databases/p5-DBD-mysql

USE_BUILDLINK2=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/mytop/.packlist
REPLACE_PERL=	mytop
NO_BUILD=	YES

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
