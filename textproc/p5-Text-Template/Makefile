# $NetBSD: Makefile,v 1.6 2001/11/22 09:45:21 martti Exp $
#

DISTNAME=       Text-Template-1.42
PKGNAME=        p5-${DISTNAME}
SVR4_PKGNAME=	p5tte
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Text/}

MAINTAINER=	packages@netbsd.org
HOMEPAGE=	http://www.plover.com/~mjd/perl/Template/
COMMENT=	perl5 library for generating form letters

USE_PERL5=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Text/Template/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
