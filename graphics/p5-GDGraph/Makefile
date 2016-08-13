# $NetBSD: Makefile,v 1.31 2016/08/13 00:44:00 wen Exp $

DISTNAME=	GDGraph-1.53
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://search.cpan.org/dist/GDGraph/
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm
LICENSE=	${PERL5_LICENSE}

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-GDTextUtil>=0.80:../../graphics/p5-GDTextUtil

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
