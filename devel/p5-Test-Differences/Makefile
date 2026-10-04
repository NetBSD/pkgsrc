# $NetBSD: Makefile,v 1.39 2026/10/04 05:48:39 wiz Exp $

DISTNAME=	Test-Differences-0.73
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DC/DCANTRELL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::Differences
COMMENT=	Test strings and data structures and show differences if not ok
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
TOOL_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
TOOL_DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
TOOL_DEPENDS+=	p5-Test-Pod>=1.22:../../devel/p5-Test-Pod

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Differences/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
