# $NetBSD: Makefile,v 1.9 2004/04/27 05:44:22 snj Exp $
#

DISTNAME=		Tie-EncryptedHash-1.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5teh
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=	
COMMENT=		Perl5 module for hashes with encrypting fields

DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES

USE_BUILDLINK3=		YES
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Tie/EncryptedHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
