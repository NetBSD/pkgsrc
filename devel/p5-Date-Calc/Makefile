# $NetBSD: Makefile,v 1.5 2001/10/18 15:20:14 veego Exp $
#

DISTNAME=     	Date-Calc-4.3
PKGNAME=       	p5-${DISTNAME}
SVR4_PKGNAME=	p5dca
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.engelschall.com/u/sb/download/
COMMENT=	perl5 module for Gregorian calendar date calculations

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Date/Calc/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
