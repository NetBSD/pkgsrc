# $NetBSD: Makefile,v 1.2 2026/07/16 19:04:42 wiz Exp $

DISTNAME=		Crypt-DSA-GMP-0.02
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DANAJ/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Crypt::DSA::GMP
COMMENT=		Perl5 module for DSA Signatures and Key Generation
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Crypt-Random-Seed>=0:../../security/p5-Crypt-Random-Seed
DEPENDS+=		p5-Math-BigInt-GMP>=0:../../math/p5-Math-BigInt-GMP
DEPENDS+=		p5-Data-Buffer>=0.04:../../devel/p5-Data-Buffer
DEPENDS+=		p5-Math-Prime-Util-GMP>=0.15:../../math/p5-Math-Prime-Util-GMP

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Crypt/DSA/GMP/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
