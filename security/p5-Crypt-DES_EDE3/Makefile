# $NetBSD: Makefile,v 1.30 2018/08/22 09:46:21 wiz Exp $
#

DISTNAME=		Crypt-DES_EDE3-0.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		13
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DES_EDE3/
COMMENT=		Perl5 module for Triple-DES EDE encryption/decryption

DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/DES_EDE3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
