# $NetBSD: Makefile,v 1.23 2020/03/22 21:05:32 nia Exp $

DISTNAME=	List-AllUtils-0.16
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/List-AllUtils
COMMENT=	Combines List::Util and List::SomeUtils
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-SomeUtils>=0.56:../../devel/p5-List-SomeUtils
DEPENDS+=	p5-List-UtilsBy>=0.11:../../devel/p5-List-UtilsBy
DEPENDS+=	p5-Scalar-List-Utils>=1.31:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=	auto/List/AllUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
