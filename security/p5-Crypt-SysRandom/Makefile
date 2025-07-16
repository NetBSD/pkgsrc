# $NetBSD: Makefile,v 1.1 2025/07/16 21:37:50 wiz Exp $

DISTNAME=		Crypt-SysRandom-0.007
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		security perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Crypt/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Crypt::SysRandom
COMMENT=		Perl interface to system randomness
LICENSE=		${PERL5_LICENSE}

#USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Crypt/SysRandom/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
