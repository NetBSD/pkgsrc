# $NetBSD: Makefile,v 1.3 2005/02/19 20:34:38 wiz Exp $
#

DISTNAME=	Term-ProgressBar-2.06-r1
PKGNAME=	p5-Term-ProgressBar-2.06.0.1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLUFFY/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/~fluffy/${DISTNAME}/
COMMENT=	Provide a progress meter on a standard terminal

DEPENDS+=	p5-Class-MethodMaker>=1.12:../../devel/p5-Class-MethodMaker
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey

WRKSRC=		${WRKDIR}/${DISTNAME:S/-r1$//}

USE_BUILDLINK3=	YES
PERL5_PACKLIST=	${PERL5_SITEARCH}/auto/Term-ProgressBar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
