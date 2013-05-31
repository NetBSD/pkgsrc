# $NetBSD: Makefile,v 1.23 2013/05/31 12:41:53 wiz Exp $
#

DISTNAME=		Crypt-DES_EDE3-0.01
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		8
SVR4_PKGNAME=		p5de3
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DES_EDE3/
COMMENT=		Perl5 module for Triple-DES EDE encryption/decryption

PKG_INSTALLATION_TYPES=	overwrite pkgviews

DEPENDS+=		p5-Crypt-DES-[0-9]*:../../security/p5-Crypt-DES

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/DES_EDE3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
