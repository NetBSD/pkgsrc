# $NetBSD: Makefile,v 1.11 2011/08/14 12:26:38 obache Exp $
#

DISTNAME=	Term-ProgressBar-2.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/F/FL/FLUFFY/}

MAINTAINER=	imil@gcu.info
HOMEPAGE=	http://search.cpan.org/dist/Term-ProgressBar/
COMMENT=	Provide a progress meter on a standard terminal

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-Class-MethodMaker>=1.12:../../devel/p5-Class-MethodMaker
DEPENDS+=	p5-Term-ReadKey>=2.21:../../devel/p5-Term-ReadKey

WRKSRC=		${WRKDIR}/${DISTNAME:S/-r1$//}

PERL5_PACKLIST=	auto/Term-ProgressBar/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
