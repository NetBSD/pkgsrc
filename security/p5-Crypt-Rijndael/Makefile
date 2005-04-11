# $NetBSD: Makefile,v 1.11 2005/04/11 21:47:16 tv Exp $
#

DISTNAME=		Crypt-Rijndael-0.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5crj
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module of the Rijndael symmetric key algorithm

PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Rijndael/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
