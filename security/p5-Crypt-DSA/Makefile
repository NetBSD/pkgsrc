# $NetBSD: Makefile,v 1.7 2002/10/27 21:20:39 seb Exp $
#

DISTNAME=		Crypt-DSA-0.12
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
SVR4_PKGNAME=		p5dsa
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		packages@netbsd.org
#HOMEPAGE=	
COMMENT=		perl5 module for the DSA public key algorithm

DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Math-Pari-[0-9]*:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random-[0-9]*:../../security/p5-Crypt-Random
DEPENDS+=		p5-Data-Buffer-[0-9]*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Convert-PEM-[0-9]*:../../textproc/p5-Convert-PEM
DEPENDS+=		p5-Class-Loader-[0-9]*:../../devel/p5-Class-Loader

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DSA/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
