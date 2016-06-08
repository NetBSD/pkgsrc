# $NetBSD: Makefile,v 1.3 2016/06/08 19:23:24 wiz Exp $

DISTNAME=	Path-FindDev-0.5.2
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KE/KENTNL/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Path-FindDev/
COMMENT=	Find a development path in an upper hierarchy
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Path/FindDev/.packlist

DEPENDS+=	p5-Path-IsDev>=0.2.2:../../devel/p5-Path-IsDev
DEPENDS+=	p5-Class-Tiny>=0.010:../../devel/p5-Class-Tiny
DEPENDS+=	p5-Path-Tiny>=0.054:../../filesystems/p5-Path-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
