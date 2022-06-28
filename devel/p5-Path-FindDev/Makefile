# $NetBSD: Makefile,v 1.12 2022/06/28 11:33:04 wiz Exp $

DISTNAME=	Path-FindDev-v0.5.3
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KE/KENTNL/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Path-FindDev
COMMENT=	Find a development path in an upper hierarchy
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Path/FindDev/.packlist

DEPENDS+=	p5-Path-IsDev>=0.2.2:../../devel/p5-Path-IsDev
DEPENDS+=	p5-Class-Tiny>=0.010:../../devel/p5-Class-Tiny
DEPENDS+=	p5-Path-Tiny>=0.054:../../filesystems/p5-Path-Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
