# $NetBSD: Makefile,v 1.17 2019/06/30 20:14:20 nia Exp $

DISTNAME=	Class-DBI-Pg-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DM/DMAKI/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-DBI-Pg
COMMENT=	Class::DBI extension for Postgres

PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI
DEPENDS+=	p5-DBD-postgresql>=1.13:../../databases/p5-DBD-postgresql

PERL5_PACKLIST=	auto/Class/DBI/Pg/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
