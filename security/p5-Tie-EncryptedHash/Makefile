# $NetBSD: Makefile,v 1.32 2018/08/22 09:46:28 wiz Exp $
#

DISTNAME=		Tie-EncryptedHash-1.24
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		10
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Tie-EncryptedHash/
COMMENT=		Perl5 module for hashes with encrypting fields

DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES

PERL5_PACKLIST=		auto/Tie/EncryptedHash/.packlist

REPLACE_PERL+=		lib/Tie/EncryptedHash.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
