# $NetBSD: Makefile,v 1.17 2017/02/11 11:09:26 mef Exp $

DISTNAME=	Math-BigInt-GMP-1.6004
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Math/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Math-BigInt-GMP/
COMMENT=	Perl module for arbitrary size integer math via the GMP library
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Math-BigInt>=1.999808:../../math/p5-Math-BigInt

PERL5_REQD+=		5.14.2 # for Math::BigInt 1.997
PERL5_PACKLIST=		auto/Math/BigInt/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
