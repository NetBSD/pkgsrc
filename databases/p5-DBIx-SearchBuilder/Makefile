# $NetBSD: Makefile,v 1.3 2001/08/10 12:07:15 mjl Exp $
#

DISTNAME=	DBIx-SearchBuilder-0.41
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
