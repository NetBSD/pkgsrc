# $NetBSD: Makefile,v 1.8 2018/08/22 09:45:38 wiz Exp $

DISTNAME=	Math-Derivative-1.01
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-Derivative
COMMENT=	Numeric 1st and 2nd order differentiation
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Derivative/.packlist

DEPENDS+=	p5-Math-Utils>=1.10:../../math/p5-Math-Utils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
