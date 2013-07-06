# $NetBSD: Makefile,v 1.1 2013/07/06 00:41:26 rodent Exp $
#

DISTNAME=	accessors-fast-0.03
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MONS/}

MAINTAINER=	rodent@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mons/accessors-fast-0.03/lib/accessors/fast.pm
COMMENT=	Compiletime accessors using Class::Accessor::Fast
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=	p5-Class-C3-[0-9]*:../../devel/p5-Class-C3
DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
DEPENDS+=	p5-Test-Simple-[0-9]*:../../devel/p5-ExtUtils-MakeMaker
DEPENDS+=	p5-constant-def>=0.01:../../devel/p5-constant-def
DEPENDS+=	p5-lib-abs>=0.90:../../devel/p5-lib-abs

REPLACE_PERL+=	cpants.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
