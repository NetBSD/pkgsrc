# $NetBSD: Makefile,v 1.26 2018/08/22 09:45:38 wiz Exp $

DISTNAME=	Math-GMP-2.19
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-GMP/
COMMENT=	Perl 5 module for high speed arbitrary size integer math
LICENSE=	gnu-gpl-v2

BUILD_DEPENDS+=	p5-Alien-GMP-[0-9]*:../../math/p5-Alien-GMP

PERL5_PACKLIST=	auto/Math/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
