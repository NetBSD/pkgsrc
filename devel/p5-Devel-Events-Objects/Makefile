# $NetBSD: Makefile,v 1.20 2022/06/28 11:32:16 wiz Exp $

DISTNAME=	Devel-Events-Objects-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	16
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Devel/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Devel-Events-Objects
COMMENT=	Perl 5 module providing object tracking support for Devel::Events

DEPENDS+=	p5-Devel-Events>=0.03:../../devel/p5-Devel-Events
DEPENDS+=	p5-Task-Weaken-[0-9]*:../../devel/p5-Task-Weaken
DEPENDS+=	p5-Tie-RefHash-Weak>=0.07:../../devel/p5-Tie-RefHash-Weak
DEPENDS+=	p5-Variable-Magic>=0.04:../../devel/p5-Variable-Magic

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Devel/Events/Objects/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
