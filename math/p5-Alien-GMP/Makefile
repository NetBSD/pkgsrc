# $NetBSD: Makefile,v 1.3 2018/08/21 11:56:38 wiz Exp $

DISTNAME=	Alien-GMP-1.14
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~plicease/Alien-GMP/
COMMENT=	Alien package for the GNU Multiple Precision library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
BUILD_DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Alien/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
