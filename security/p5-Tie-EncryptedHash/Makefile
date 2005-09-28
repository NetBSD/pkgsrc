# $NetBSD: Makefile,v 1.14 2005/09/28 14:31:08 rillig Exp $
#

DISTNAME=		Tie-EncryptedHash-1.1
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5teh
PKGREVISION=		2
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		tech-pkg@NetBSD.org
#HOMEPAGE=
COMMENT=		Perl5 module for hashes with encrypting fields

DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES

PERL5_PACKLIST=		auto/Tie/EncryptedHash/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
