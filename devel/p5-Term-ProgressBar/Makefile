# $NetBSD: Makefile,v 1.26 2019/08/11 13:20:25 wiz Exp $

DISTNAME=	Term-ProgressBar-2.22
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SZ/SZABGAB/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	https://metacpan.org/release/Term-ProgressBar
COMMENT=	Provide a progress meter on a standard terminal

LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-MethodMaker>=1.02:../../devel/p5-Class-MethodMaker
DEPENDS+=	p5-Term-ReadKey>=2.24:../../devel/p5-Term-ReadKey

TEST_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

WRKSRC=		${WRKDIR}/${DISTNAME:S/-r1$//}

PERL5_PACKLIST=		auto/Term/ProgressBar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
