# $NetBSD: Makefile,v 1.10 2001/10/18 15:20:08 veego Exp $
#

DISTNAME=	DBI-1.19
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5dbi
CATEGORIES=	databases perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=DBD/}

MAINTAINER=	bad@netbsd.org
HOMEPAGE=	http://www.symbolstone.org/technology/perl/DBI/index.html
COMMENT=	the database-independent Perl database access API

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/DBI/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
