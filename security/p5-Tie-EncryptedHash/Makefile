# $NetBSD: Makefile,v 1.18 2007/04/22 09:00:22 heinz Exp $
#

DISTNAME=		Tie-EncryptedHash-1.21
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5teh
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=		pkgsrc-users@NetBSD.org
#HOMEPAGE=
COMMENT=		Perl5 module for hashes with encrypting fields

DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/Tie/EncryptedHash/.packlist

REPLACE_PERL+=		lib/Tie/EncryptedHash.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
