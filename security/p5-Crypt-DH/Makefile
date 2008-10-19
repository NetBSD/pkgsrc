# $NetBSD: Makefile,v 1.5 2008/10/19 19:18:45 he Exp $
#

DISTNAME=		Crypt-DH-0.06
PKGNAME=		p5-Crypt-DH-0.06
PKGREVISION=		1
SVR4_PKGNAME=		p5cdh
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DH/
COMMENT=		Perl5 module for the Diffie-Hellman key exchange system

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=		p5-Math-Pari>=2.001804:../../math/p5-Math-Pari
DEPENDS+=		p5-Crypt-Random>=0.33:../../security/p5-Crypt-Random

USE_LANGUAGES=		# empty

PERL5_PACKLIST=		auto/Crypt/DH/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
