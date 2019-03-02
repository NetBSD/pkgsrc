# $NetBSD: Makefile,v 1.23 2019/03/02 10:35:43 wen Exp $

DISTNAME=	Test-Differences-0.66
PKGNAME=	p5-${DISTNAME}00
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/perldoc?Test::Differences
COMMENT=	Test strings and data structures and show differences if not ok
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-Diff>=0.35:../../textproc/p5-Text-Diff
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Test-Pod-Coverage>=1.08:../../devel/p5-Test-Pod-Coverage
BUILD_DEPENDS+=	p5-Test-Pod>=1.22:../../devel/p5-Test-Pod

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Differences/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
