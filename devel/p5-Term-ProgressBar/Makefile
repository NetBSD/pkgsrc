# $NetBSD: Makefile,v 1.14 2012/10/31 11:19:01 asau Exp $

DISTNAME=	Term-ProgressBar-2.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SZ/SZABGAB/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/Term-ProgressBar/
COMMENT=	Provide a progress meter on a standard terminal

LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-MethodMaker>=1.02:../../devel/p5-Class-MethodMaker
DEPENDS+=	p5-Term-ReadKey>=2.24:../../devel/p5-Term-ReadKey

WRKSRC=		${WRKDIR}/${DISTNAME:S/-r1$//}

PERL5_PACKLIST=		auto/Term/ProgressBar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
