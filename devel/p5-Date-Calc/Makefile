# $NetBSD: Makefile,v 1.3 2001/02/16 14:38:47 wiz Exp $
#

DISTNAME=     	Date-Calc-4.2
PKGNAME=       	p5-${DISTNAME}
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
