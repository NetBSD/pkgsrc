# $NetBSD: Makefile,v 1.1.1.1 2001/05/14 12:37:03 zuntum Exp $
#

DISTNAME=	mytop-0.7
CATEGORIES=	databases
MASTER_SITES=	http://public.yahoo.com/~jzawodn/mytop/

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://public.yahoo.com/~jzawodn/mytop/
COMMENT=	console-based tool for monitoring the threads and performance of MySQL

DEPENDS+=	p5-DBI-*:../../databases/p5-DBI
DEPENDS+=	p5-Term-ReadKey-*:../../devel/p5-Term-ReadKey
DEPENDS+=	p5-DBD-mysql-*:../../databases/p5-DBD-mysql

USE_PERL5=	YES
NO_BUILD=	YES

post-patch:
	${SED} "s,/usr/bin/perl,${LOCALBASE}/bin/perl,"		\
		${WRKSRC}/mytop > ${WRKSRC}/mytop.done
	${MV} ${WRKSRC}/mytop.done ${WRKSRC}/mytop

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mytop ${PREFIX}/bin
	${INSTALL_DATA_DIR} ${PREFIX}/share/doc/mytop
	${INSTALL_DATA} ${WRKSRC}/README ${PREFIX}/share/doc/mytop
	${INSTALL_DATA} ${WRKSRC}/mytop.html ${PREFIX}/share/doc/mytop

.include "../../mk/bsd.pkg.mk"
