# $NetBSD: Makefile,v 1.2 2005/04/11 21:45:12 tv Exp $
#

DISTNAME=	Class-DBI-AbstractSearch-0.05
PKGNAME=	p5-${DISTNAME}
#SVR4_PKGNAME=	p5cdi
CATEGORIES=	perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	tech-pkg@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-DBI-AbstractSearch/
COMMENT=	Abstract Class::DBI's SQL with SQL::Abstract

DEPENDS+=	p5-Class-DBI>=0.9:../../databases/p5-Class-DBI
DEPENDS+=	p5-SQL-Abstract>=1.1:../../databases/p5-SQL-Abstract

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Class/DBI/AbstractSearch/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
