# $NetBSD: Makefile,v 1.35 2023/07/06 09:40:10 wiz Exp $

DISTNAME=	Test-Class-0.52
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Class
COMMENT=	Easily create test classes in an xUnit/JUnit style
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-MRO-Compat>=0.11:../../devel/p5-MRO-Compat
#DEPENDS+=	{perl>=5.10.0,p5-Storable>=2.04}:../../devel/p5-Storable
#DEPENDS+=	{perl>=5.20.0,p5-Test-Simple>=1.001002}:../../devel/p5-Test-Simple

TOOL_DEPENDS+=	p5-Test-Exception>=0.25:../../devel/p5-Test-Exception
# for make test
TOOL_DEPENDS+=	p5-Try-Tiny-[0-9]*:../../devel/p5-Try-Tiny
TOOL_DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Test/Class/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
