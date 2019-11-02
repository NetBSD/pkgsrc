# $NetBSD: Makefile,v 1.16 2019/11/02 22:38:01 rillig Exp $

DISTNAME=	GDGraph-boxplot-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	10
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/GDGraph-boxplot
COMMENT=	Boxplot - Box and Whisker Graph Module for Perl 5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-GDGraph>=1.30:../../graphics/p5-GDGraph
DEPENDS+=	p5-Statistics-Descriptive>=2.4:../../math/p5-Statistics-Descriptive

PERL5_PACKLIST=		auto/GD/Graph/boxplot/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
