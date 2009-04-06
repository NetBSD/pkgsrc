# $NetBSD: Makefile,v 1.1.1.1 2009/04/06 19:07:13 chuck Exp $

DISTNAME=	GDGraph-boxplot-1.00
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GDGraph-boxplot/
COMMENT=	Boxplot - Box and Whisker Graph Module for Perl 5.

DEPENDS+= p5-GDGraph>=1.30:../../graphics/p5-GDGraph
DEPENDS+= p5-Statistics-Descriptive>=2.4:../../math/p5-Statistics-Descriptive

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/GD/Graph/boxplot/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
