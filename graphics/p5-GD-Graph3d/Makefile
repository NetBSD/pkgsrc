# $NetBSD: Makefile,v 1.14 2019/08/11 13:21:13 wiz Exp $

DISTNAME=	GD-Graph3d-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm
HOMEPAGE=	https://metacpan.org/release/GD-Graph3d
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph>=1.30:../../graphics/p5-GDGraph
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil

CONFLICTS+=	p5-GDGraph3d-[0-9]*
SUPERSEDES=	p5-GDGraph3d<=0.63

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph3d/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
