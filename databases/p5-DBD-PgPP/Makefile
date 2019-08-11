# $NetBSD: Makefile,v 1.18 2019/08/11 13:18:24 wiz Exp $

DISTNAME=	DBD-PgPP-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	ficovh@yahoo.com
HOMEPAGE=	https://metacpan.org/release/DBD-PgPP
COMMENT=	DBD::PgPP - Pure Perl PostgreSQL driver for the DBI
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/DBD/PgPP/.packlist
USE_LANGUAGES=	# none

BUILDLINK_API_DEPENDS.p5-DBI+=	p5-DBI>=1.59

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
