# $NetBSD: Makefile,v 1.26 2011/08/14 14:42:49 obache Exp $
#

DISTNAME=		Crypt-RSA-1.99
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		2
SVR4_PKGNAME=		p5rsa
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-RSA/
COMMENT=		Perl5 module of the RSA public key algorithm
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Class-Loader>=2.00:../../devel/p5-Class-Loader
DEPENDS+=		p5-Convert-ASCII-Armour-[0-9]*:../../textproc/p5-Convert-ASCII-Armour
DEPENDS+=		p5-Crypt-Blowfish-[0-9]*:../../security/p5-Crypt-Blowfish
DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC
DEPENDS+=		p5-Crypt-Primes>=0.38:../../security/p5-Crypt-Primes
DEPENDS+=		p5-Crypt-Random>=0.34:../../security/p5-Crypt-Random
DEPENDS+=		p5-Data-Buffer-[0-9]*:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Digest-MD2-[0-9]*:../../security/p5-Digest-MD2
DEPENDS+=		p5-Digest-MD5>=2.16:../../security/p5-Digest-MD5
DEPENDS+=		p5-Digest-SHA1-[0-9]*:../../security/p5-Digest-SHA1
DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari
DEPENDS+=		p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
DEPENDS+=		p5-Tie-EncryptedHash-[0-9]*:../../security/p5-Tie-EncryptedHash

PKG_INSTALLATION_TYPES=	overwrite pkgviews
PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/RSA/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

REPLACE_PERL+=		lib/Crypt/RSA.pm
REPLACE_PERL+=		lib/Crypt/RSA/*.pm
REPLACE_PERL+=		lib/Crypt/RSA/ES/*.pm
REPLACE_PERL+=		lib/Crypt/RSA/Key/*.pm
REPLACE_PERL+=		lib/Crypt/RSA/Key/Private/*.pm
REPLACE_PERL+=		lib/Crypt/RSA/Key/Public/*.pm
REPLACE_PERL+=		lib/Crypt/RSA/SS/*.pm

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
