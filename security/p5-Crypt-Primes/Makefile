# $NetBSD: Makefile,v 1.1 2001/10/01 00:33:14 mcr Exp $
#

DISTNAME=		Crypt-Primes-0.49
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for provable prime number generation

DEPENDS+=		p5-Math-Pari-*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random-*:../../security/p5-Crypt-Random

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Primes/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
