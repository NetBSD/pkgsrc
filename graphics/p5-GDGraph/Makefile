# $NetBSD: Makefile,v 1.30 2016/06/08 19:23:53 wiz Exp $

DISTNAME=	GDGraph-1.48
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
HOMEPAGE=	http://search.cpan.org/dist/GDGraph/
COMMENT=	GDGraph is a package to generate charts, using Lincoln Stein's GD.pm

DEPENDS+=		p5-GD>=1.18:../../graphics/p5-GD
DEPENDS+=		p5-GDTextUtil>=0.80:../../graphics/p5-GDTextUtil

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
