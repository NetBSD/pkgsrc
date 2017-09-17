# $NetBSD: Makefile,v 1.22 2017/09/17 13:11:25 wiz Exp $

DISTNAME=	Term-ProgressBar-2.21
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SZ/SZABGAB/}
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Term/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/Term-ProgressBar/
COMMENT=	Provide a progress meter on a standard terminal

LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-MethodMaker>=1.02:../../devel/p5-Class-MethodMaker
DEPENDS+=	p5-Term-ReadKey>=2.24:../../devel/p5-Term-ReadKey
# for make test
BUILD_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

WRKSRC=		${WRKDIR}/${DISTNAME:S/-r1$//}

PERL5_PACKLIST=		auto/Term/ProgressBar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
