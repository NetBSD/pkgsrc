# $NetBSD: Makefile,v 1.12 2016/06/08 19:22:30 wiz Exp $
#

DISTNAME=	SQL-Abstract-Limit-0.141
PKGNAME=	p5-SQL-Abstract-Limit-0.14.1
PKGREVISION=	7
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=SQL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/SQL-Abstract-Limit/
COMMENT=	Generate SQL from Perl data structures

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Deep-[0-9]*:../../devel/p5-Test-Deep

DEPENDS+=	p5-SQL-Abstract>=1.2:../../databases/p5-SQL-Abstract
DEPENDS+=	p5-DBI-[0-9]*:../../databases/p5-DBI

PERL5_PACKLIST=		auto/SQL/Abstract/Limit/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
