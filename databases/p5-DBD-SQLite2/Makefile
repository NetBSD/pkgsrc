# $NetBSD: Makefile,v 1.23 2023/07/06 09:38:21 wiz Exp $

DISTNAME=	DBD-SQLite2-0.38
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-SQLite2
COMMENT=	Perl DBI/DBD driver for sqlite v2 databases
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/DBD/SQLite2/.packlist

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
