# $NetBSD: Makefile,v 1.1.1.1 2000/03/07 23:15:57 jwise Exp $
#

DISTNAME=     	DateManip-5.37
PKGNAME=       	p5-Date-Manip-5.37
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.cpan.org/

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
