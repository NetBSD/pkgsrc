# $NetBSD: Makefile,v 1.8 2011/08/14 14:42:47 obache Exp $
#

DISTNAME=		Crypt-DH-0.06
PKGNAME=		p5-Crypt-DH-0.06
PKGREVISION=		4
SVR4_PKGNAME=		p5cdh
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DH/
COMMENT=		Perl5 module for the Diffie-Hellman key exchange system
LICENSE=		${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Math-BigInt-GMP-[0-9]*:../../math/p5-Math-BigInt-GMP
DEPENDS+=		p5-Math-BigInt-Pari-[0-9]*:../../math/p5-Math-BigInt-Pari
DEPENDS+=		p5-Crypt-Random>=0.33:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Crypt/DH/.packlist
MAKE_PARAMS+=		--skipdeps

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
