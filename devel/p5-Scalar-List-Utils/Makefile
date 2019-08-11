# $NetBSD: Makefile,v 1.45 2019/08/11 10:15:45 adam Exp $

DISTNAME=	Scalar-List-Utils-1.51
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel misc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Scalar/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Scalar-List-Utils
COMMENT=	Common Scalar and List utility subroutines
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	c99

PERL5_PACKLIST=	auto/List/Util/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
