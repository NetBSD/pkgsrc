# $NetBSD: Makefile,v 1.4 2011/08/14 12:59:49 obache Exp $

DISTNAME=	GDGraph-boxplot-1.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/GDGraph-boxplot/
COMMENT=	Boxplot - Box and Whisker Graph Module for Perl 5.
LICENSE=	${PERL5_LICENSE}

DEPENDS+= p5-GDGraph>=1.30:../../graphics/p5-GDGraph
DEPENDS+= p5-Statistics-Descriptive>=2.4:../../math/p5-Statistics-Descriptive

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=		auto/GD/Graph/boxplot/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
