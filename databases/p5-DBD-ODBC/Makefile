# $NetBSD: Makefile,v 1.32 2024/11/16 12:03:23 wiz Exp $

DISTNAME=	DBD-ODBC-1.61
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/DBD-ODBC
COMMENT=	Perl DBI/DBD driver for ODBC
LICENSE=	${PERL5_LICENSE}

.include "options.mk"

PERL5_PACKLIST=	auto/DBD/ODBC/.packlist

MAKE_ENV+=	PERL_MM_USE_DEFAULT=1

.include "../../databases/p5-DBI/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
