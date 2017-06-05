# $NetBSD: Makefile,v 1.16 2017/06/05 14:24:10 ryoon Exp $

DISTNAME=		Math-BigInt-Pari-1.3003
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		math perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Math-BigInt-Pari/
COMMENT=		Perl5 library to use Math::Pari for Math::BigInt routines
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Math-Pari>=2.010709:../../math/p5-Math-Pari
DEPENDS+=               p5-Math-BigInt>=1.999808:../../math/p5-Math-BigInt

PERL5_REQD+=		5.12.2nb1

PERL5_PACKLIST=		auto/Math/BigInt/Pari/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
