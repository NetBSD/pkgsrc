# $NetBSD: Makefile,v 1.18 2002/10/10 12:13:05 wiz Exp $
#

DISTNAME=		DBD-mysql-2.1017
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5dmy
CATEGORIES=		databases perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		bad@netbsd.org
HOMEPAGE=		http://www.mysql.com/
COMMENT=		Perl DBI/DBD driver for MySQL databases

DEPENDS+=		p5-Data-ShowTable-3.3:../../devel/p5-Data-ShowTable

BUILDLINK_DEPENDS.mysql-client?=	mysql-client>=3.23.49nb1

USE_BUILDLINK2=		# defined

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/mysql/.packlist

MAKE_PARAMS+=		--nocatchstderr

.include "../../databases/mysql-client/buildlink2.mk"
.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
