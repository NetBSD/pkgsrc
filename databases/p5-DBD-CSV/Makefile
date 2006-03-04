# $NetBSD: Makefile,v 1.20 2006/03/04 21:29:09 jlam Exp $
#

DISTNAME=	DBD-CSV-0.22
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dcs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/DBD-CSV/
COMMENT=	Access CSV files via DBI

DEPENDS+=	p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=	p5-SQL-Statement>=0.1016:../../databases/p5-SQL-Statement
DEPENDS+=	p5-Text-CSV_XS>=0.20:../../textproc/p5-Text-CSV_XS

PERL5_PACKLIST=	auto/DBD/CSV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
