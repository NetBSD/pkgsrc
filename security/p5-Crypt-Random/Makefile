# $NetBSD: Makefile,v 1.4 2002/03/13 17:37:42 fredb Exp $
#

DISTNAME=		Crypt-Random-1.11
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5cra
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 interface to /dev/random

DEPENDS+=		p5-Class-Loader-[0-9]*:../../devel/p5-Class-Loader
DEPENDS+=		p5-Math-Pari-[0-9]*:../../math/p5-Math-Pari

USE_PERL5=		# defined
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Random/.packlist

do-configure:
	@cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include "../../mk/bsd.pkg.mk"
