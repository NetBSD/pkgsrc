# $NetBSD: Makefile,v 1.1.1.1 2001/03/25 04:43:40 mjl Exp $
#

DISTNAME=	DBIx-SearchBuilder-0.26
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBIx/}

MAINTAINER=	packages@netbsd.org
COMMENT=	extension for easy SQL SELECT Statement generation

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBIx/SearchBuilder/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
