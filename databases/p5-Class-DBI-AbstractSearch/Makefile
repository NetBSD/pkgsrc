# $NetBSD: Makefile,v 1.24 2022/06/28 11:31:20 wiz Exp $
#

DISTNAME=	Class-DBI-AbstractSearch-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-DBI-AbstractSearch
COMMENT=	Abstract Class::DBI's SQL with SQL::Abstract

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI
DEPENDS+=	p5-SQL-Abstract-Limit>=0.1:../../databases/p5-SQL-Abstract-Limit

PERL5_PACKLIST=	auto/Class/DBI/AbstractSearch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
