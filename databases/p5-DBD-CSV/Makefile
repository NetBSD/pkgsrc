# $NetBSD: Makefile,v 1.10 2002/10/20 23:35:11 seb Exp $
#

DISTNAME=	DBD-CSV-0.2001
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dcs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://
COMMENT=	Access CSV files via DBI

DEPENDS+=               p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=               p5-SQL-Statement>=0.1016:../../databases/p5-SQL-Statement
DEPENDS+=               p5-Text-CSV_XS>=0.20:../../textproc/p5-Text-CSV_XS

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/CSV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
