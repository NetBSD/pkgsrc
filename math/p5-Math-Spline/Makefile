# $NetBSD: Makefile,v 1.5 2017/06/05 14:24:11 ryoon Exp $

DISTNAME=	Math-Spline-0.02
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Spline
COMMENT=	Cubic Spline Interpolation of data
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-Derivative-[0-9]*:../../math/p5-Math-Derivative

PERL5_PACKLIST=	auto/Math/Spline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
