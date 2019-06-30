# $NetBSD: Makefile,v 1.15 2019/06/30 20:15:55 nia Exp $
#

DISTNAME=	Test-Pod-Spelling-CommonMistakes-1.001
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Pod-Spelling-CommonMistakes
COMMENT=	Checks POD for common spelling mistake
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Pod-Spell-CommonMistakes>=0.01:../../textproc/p5-Pod-Spell-CommonMistakes
#DEPENDS+=	{perl>=5.12,p5-Test-Simple>=0.94}:../../devel/p5-Test-Simple
DEPENDS+=	p5-Test-Pod>=1.40:../../devel/p5-Test-Pod

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Pod/Spelling/CommonMistakes/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
