# $NetBSD: Makefile,v 1.14 2004/04/27 02:27:36 snj Exp $
#

DISTNAME=	DBD-CSV-0.2002
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dcs
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	tech-pkg@NetBSD.org
# HOMEPAGE=	http://
COMMENT=	Access CSV files via DBI

DEPENDS+=               p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=               p5-SQL-Statement>=0.1016:../../databases/p5-SQL-Statement
DEPENDS+=               p5-Text-CSV_XS>=0.20:../../textproc/p5-Text-CSV_XS

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/CSV/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
