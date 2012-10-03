# $NetBSD: Makefile,v 1.13 2012/10/03 21:56:12 wiz Exp $

DISTNAME=	Chart-ThreeD-0.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
SVR4_PKGNAME=	p5c3d
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Chart/}

MAINTAINER=	he@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Chart-ThreeD/
COMMENT=	Three-Dimentional pie chart plotting

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-GD>=2.16:../../graphics/p5-GD

PERL5_PACKLIST=		auto/Chart-ThreeD/.packlist

REPLACE_PERL+=	pie.pl

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
