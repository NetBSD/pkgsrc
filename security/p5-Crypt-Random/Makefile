# $NetBSD: Makefile,v 1.5 2002/10/27 21:20:38 seb Exp $
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

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Random/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
