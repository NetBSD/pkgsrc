# $NetBSD: Makefile,v 1.1.1.1 2000/10/23 13:57:03 mjl Exp $
#

DISTNAME=	DBD-CSV-0.1022
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	packages@netbsd.org
# HOMEPAGE=	http://

DEPENDS+=               p5-DBI>=1.13:../../databases/p5-DBI
DEPENDS+=               p5-SQL-Statement>=0.1016:../../databases/p5-SQL-Statement
DEPENDS+=               p5-Text-CSV_XS>=0.20:../../textproc/p5-Text-CVS_XS

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBD/CSV/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
