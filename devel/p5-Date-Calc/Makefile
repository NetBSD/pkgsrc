# $NetBSD: Makefile,v 1.1.1.1 1999/12/28 12:08:17 simonb Exp $
#

DISTNAME=     	Date-Calc-4.2
PKGNAME=       	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/u/sb/download/

USE_PERL5=	YES

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PREFIX}/bin/perl Makefile.PL

.include "../../mk/bsd.pkg.mk"
