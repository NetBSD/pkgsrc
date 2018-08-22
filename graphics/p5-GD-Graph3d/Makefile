# $NetBSD: Makefile,v 1.12 2018/08/22 09:45:15 wiz Exp $

DISTNAME=	GD-Graph3d-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	9
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm
HOMEPAGE=	http://search.cpan.org/dist/GD-Graph3d/
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
