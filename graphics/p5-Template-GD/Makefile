# $NetBSD: Makefile,v 1.22 2022/06/28 11:34:07 wiz Exp $

DISTNAME=	Template-GD-2.66
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	15
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/A/AB/ABW/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Template-GD
COMMENT=	GD plugin(s) for the Template Toolkit
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Template/GD/.packlist
USE_LANGUAGES=	# none

DEPENDS+=	p5-GD>=1.14:../../graphics/p5-GD
DEPENDS+=	p5-Template-Toolkit>=2.14:../../www/p5-Template-Toolkit

# Recommended dependency
DEPENDS+=	p5-GDGraph-[0-9]*:../../graphics/p5-GDGraph
DEPENDS+=	p5-GD-Graph3d-[0-9]*:../../graphics/p5-GD-Graph3d
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
