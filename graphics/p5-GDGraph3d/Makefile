# $NetBSD: Makefile,v 1.15 2008/06/20 01:09:22 joerg Exp $

DISTNAME=	GDGraph3d-0.56
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
SVR4_PKGNAME=	p5gd3
CATEGORIES=	graphics perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=GD/}

MAINTAINER=	damon@brodiefamily.org
COMMENT=	GDGraph3d is a pkg to generate charts, using Lincoln Stein's GD.pm

PKG_DESTDIR_SUPPORT=	user-destdir

DEPENDS+=	p5-GDGraph>=1.30:../../graphics/p5-GDGraph

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/GD/Graph3d/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
