# $NetBSD: Makefile,v 1.7 2001/11/26 06:49:40 jlam Exp $
#

DISTNAME=	DBD-CSV-0.1027
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

USE_BUILDLINK_ONLY=	YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/DBD/CSV/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../lang/perl5/buildlink.mk"
.include "../../mk/bsd.pkg.mk"
