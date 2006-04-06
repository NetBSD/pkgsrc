# $NetBSD: Makefile,v 1.9 2006/04/06 06:21:41 reed Exp $
#

DISTNAME=		DBD-Google-0.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
CATEGORIES=		databases perl5 www
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=		pkgsrc-users@NetBSD.org
COMMENT=		Perl DBI/DBD driver for using Google as a datasource

DEPENDS+=		p5-Net-Google>=0.61:../../net/p5-Net-Google

PERL5_PACKLIST=		auto/DBD/Google/.packlist

BUILDLINK_API_DEPENDS.p5-DBI?=	p5-DBI>=1.39

.include "../../databases/p5-DBI/buildlink3.mk"

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
