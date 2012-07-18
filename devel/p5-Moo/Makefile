# $NetBSD: Makefile,v 1.2 2012/07/18 08:04:49 sno Exp $

DISTNAME=	Moo-0.091014
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/M/MS/MSTROUT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Moo/
COMMENT=	Minimalist Object Orientation (with Moose compatiblity)
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Class-Method-Modifiers>=1.05:../../devel/p5-Class-Method-Modifiers
DEPENDS+=	p5-Module-Runtime>=0.012:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Role-Tiny>=1.001003:../../devel/p5-Role-Tiny
DEPENDS+=	p5-strictures>=1.001001:../../devel/p5-strictures

PKG_DESTDIR_SUPPORT=	user-destdir

PERL5_PACKLIST=	auto/Moo/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
