# $NetBSD: Makefile,v 1.3 2001/10/18 15:20:08 veego Exp $
#

DISTNAME=	DBIx-DataSource-0.02
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dxd
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.420.am/dbix-datasource
COMMENT=	create and drop functions for databases

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBIx/DataSource/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
