# $NetBSD: Makefile,v 1.1.1.1 2004/04/09 11:33:16 grant Exp $
#

DISTNAME=		DBD-Google-0.11
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		databases perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl DBI/DBD driver for using Google as a datasource

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Google/.packlist

.include "../../databases/p5-DBI/buildlink2.mk"
.include "../../net/p5-Net-Google/buildlink2.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
