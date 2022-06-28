# $NetBSD: Makefile,v 1.22 2022/06/28 11:31:21 wiz Exp $

DISTNAME=	Class-DBI-Pg-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DM/DMAKI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-DBI-Pg
COMMENT=	Class::DBI extension for Postgres

PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI
DEPENDS+=	p5-DBD-postgresql>=1.13:../../databases/p5-DBD-postgresql

PERL5_PACKLIST=	auto/Class/DBI/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
