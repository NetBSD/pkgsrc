# $NetBSD: Makefile,v 1.5 2005/04/11 21:45:35 tv Exp $
#

DISTNAME=	Term-ProgressBar-2.09
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLUFFY/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/Term-ProgressBar/
COMMENT=	Provide a progress meter on a standard terminal

DEPENDS+=	p5-Class-MethodMaker>=1.12:../../devel/p5-Class-MethodMaker
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey

WRKSRC=		${WRKDIR}/${DISTNAME:S/-r1$//}

PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Term-ProgressBar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
