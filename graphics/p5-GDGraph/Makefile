# $NetBSD: Makefile,v 1.42 2023/07/06 09:40:38 wiz Exp $

DISTNAME=	GDGraph-1.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	https://metacpan.org/release/GDGraph
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-GDTextUtil>=0.80:../../graphics/p5-GDTextUtil

# for make test
TOOL_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
TOOL_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
