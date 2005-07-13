# $NetBSD: Makefile,v 1.6 2005/07/13 18:01:20 jlam Exp $
#

DISTNAME=		DBD-Google-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		databases perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl DBI/DBD driver for using Google as a datasource

PERL5_PACKLIST=		auto/DBD/Google/.packlist

BUILDLINK_DEPENDS.p5-DBI?=	p5-DBI>=1.39

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../net/p5-Net-Google/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
