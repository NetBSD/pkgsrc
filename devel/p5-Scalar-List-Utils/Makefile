# $NetBSD: Makefile,v 1.53 2021/10/24 08:30:50 wen Exp $

DISTNAME=	Scalar-List-Utils-1.60
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
