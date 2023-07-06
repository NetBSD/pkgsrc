# $NetBSD: Makefile,v 1.20 2023/07/06 09:40:26 wiz Exp $

DISTNAME=	accessors-fast-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MO/MONS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/accessors-fast
COMMENT=	Compiletime accessors using Class::Accessor::Fast
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-Class-Accessor-[0-9]*:../../devel/p5-Class-Accessor
DEPENDS+=		p5-Class-C3-[0-9]*:../../devel/p5-Class-C3
TOOL_DEPENDS+=		p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
DEPENDS+=		p5-constant-def>=0.01:../../devel/p5-constant-def
TOOL_DEPENDS+=		p5-lib-abs>=0.90:../../devel/p5-lib-abs

REPLACE_PERL+=	cpants.pl

MAKE_ENV+=	PERL_USE_UNSAFE_INC=1

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
