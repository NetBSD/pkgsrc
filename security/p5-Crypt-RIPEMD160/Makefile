# $NetBSD: Makefile,v 1.35 2021/09/05 06:38:54 wen Exp $
#

DISTNAME=		Crypt-RIPEMD160-0.08
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Crypt-RIPEMD160
COMMENT=		Perl5 module of the RIPEMD160 hash function
LICENSE=		${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Crypt/RIPEMD160/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
