# $NetBSD: Makefile,v 1.27 2014/02/16 19:30:35 sno Exp $
#

DISTNAME=	Scalar-List-Utils-1.38
PKGNAME=	p5-${DISTNAME}
SVR4_PKGNAME=	p5slu
CATEGORIES=	devel misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PE/PEVANS/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Scalar-List-Utils
COMMENT=	Common Scalar and List utility subroutines
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c

PERL5_PACKLIST=	auto/Scalar/List/Utils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
