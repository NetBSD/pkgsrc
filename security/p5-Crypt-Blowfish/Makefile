# $NetBSD: Makefile,v 1.10 2003/07/21 17:20:13 martti Exp $
#

DISTNAME=		Crypt-Blowfish-2.09
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5cbl
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		tech-pkg@NetBSD.org
COMMENT=		Perl5 Blowfish implementation

CRYPTO=			YES

USE_BUILDLINK2=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/Blowfish/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
