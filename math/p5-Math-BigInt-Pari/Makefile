# $NetBSD: Makefile,v 1.30 2024/05/27 08:41:54 wen Exp $

DISTNAME=		Math-BigInt-Pari-1.3014
PKGNAME=		p5-${DISTNAME}
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Math-BigInt-Pari
COMMENT=		Perl5 library to use Math::Pari for Math::BigInt routines
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Math-Pari>=2.030523:../../math/p5-Math-Pari
DEPENDS+=		p5-Math-BigInt>=2.003001:../../math/p5-Math-BigInt

PERL5_REQD+=		5.12.2nb1

PERL5_PACKLIST=		auto/Math/BigInt/Pari/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
