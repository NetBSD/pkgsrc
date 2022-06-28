# $NetBSD: Makefile,v 1.34 2022/06/28 11:35:41 wiz Exp $
#

DISTNAME=		Crypt-DES-2.07
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		9
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-DES
COMMENT=		XS-based DES implementation for Perl

BUILD_DEPENDS+=		p5-Crypt-CBC-[0-9]*:../../security/p5-Crypt-CBC

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/DES/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
