# $NetBSD: Makefile,v 1.3 2000/08/27 10:37:01 jlam Exp $
#

DISTNAME=	DBI-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.symbolstone.org/technology/perl/DBI/index.html

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
