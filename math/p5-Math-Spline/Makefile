# $NetBSD: Makefile,v 1.8 2019/08/11 13:21:49 wiz Exp $

DISTNAME=	Math-Spline-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Math-Spline
COMMENT=	Cubic Spline Interpolation of data
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-Derivative-[0-9]*:../../math/p5-Math-Derivative

PERL5_PACKLIST=	auto/Math/Spline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
