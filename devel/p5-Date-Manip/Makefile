# $NetBSD: Makefile,v 1.5 2001/02/28 12:51:39 wiz Exp $
#

DISTNAME=     	DateManip-5.39
PKGNAME=       	p5-Date-Manip-5.39
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Date/}

MAINTAINER=	jwise@netbsd.org
HOMEPAGE=	http://www.cpan.org/
COMMENT=	perl5 module for date calculations

USE_PERL5=	# defined
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Date/Manip/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
