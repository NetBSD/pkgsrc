# $NetBSD: Makefile,v 1.25 2004/11/21 15:01:05 kristerw Exp $
#

DISTNAME=		DBD-mysql-2.9004
PKGNAME=		p5-${DISTNAME}
PKGREVISION=	1
SVR4_PKGNAME=		p5dmy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		bad@NetBSD.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		Perl DBI/DBD driver for MySQL databases

DEPENDS+=		p5-Data-ShowTable-3.3:../../devel/p5-Data-ShowTable

BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.23.49nb1

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/mysql/.packlist

MAKE_PARAMS+=		--nocatchstderr
PTHREAD_OPTS+=		require

.include "../../mk/mysql.buildlink3.mk"
.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/pthread.buildlink3.mk"
.include "../../mk/bsd.pkg.mk"
