# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:12 tv Exp $
#

DISTNAME=		DBD-Google-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl DBI/DBD driver for using Google as a datasource

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/Google/.packlist

BUILDLINK_DEPENDS.p5-DBI?=	p5-DBI>=1.39

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../net/p5-Net-Google/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
