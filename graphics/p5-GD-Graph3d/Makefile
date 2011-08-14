# $NetBSD: Makefile,v 1.3 2011/08/14 12:59:48 obache Exp $

DISTNAME=	GD-Graph3d-0.63
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
SVR4_PKGNAME=	p5gd3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm
HOMEPAGE=	http://search.cpan.org/dist/GD-Graph3d/
LICENSE=	${PERL5_LICENSE}

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=	p5-GDGraph>=1.30:../../graphics/p5-GDGraph
DEPENDS+=	p5-GDTextUtil-[0-9]*:../../graphics/p5-GDTextUtil

CONFLICTS+=	p5-GDGraph3d-[0-9]*
SUPERSEDES=	p5-GDGraph3d<=0.63

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph3d/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
