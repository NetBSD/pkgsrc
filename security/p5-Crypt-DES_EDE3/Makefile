# $NetBSD: Makefile,v 1.10 2005/04/11 21:47:15 tv Exp $
#

DISTNAME=		Crypt-DES_EDE3-0.01
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5de3
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		heinz@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Crypt-DES_EDE3/
COMMENT=		Perl5 module for Triple-DES EDE encryption/decryption

PKG_INSTALLATION_TYPES=	overwrite pkgviews

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		${PERL5_SITEARCH}/auto/Crypt/DES_EDE3/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
