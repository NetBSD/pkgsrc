# $NetBSD: Makefile,v 1.10 2004/12/20 11:31:08 grant Exp $
#

DISTNAME=		Crypt-Rijndael-0.05
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5crj
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 module of the Rijndael symmetric key algorithm

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Rijndael/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
