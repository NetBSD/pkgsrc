# $NetBSD: Makefile,v 1.20 2022/06/28 11:33:34 wiz Exp $
#

DISTNAME=	Tie-RefHash-Weak-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	14
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Tie/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Tie-RefHash-Weak
COMMENT=	Perl 5 Tie::RefHash subclass with weakened references in the keys

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Tie/RefHash/Weak/.packlist

DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
#DEPENDS+=	{perl>=5.9.4,p5-Tie-RefHash>=1.34}:../../devel/p5-Tie-RefHash
DEPENDS+=	p5-Variable-Magic-[0-9]*:../../devel/p5-Variable-Magic

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
