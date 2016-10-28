# $NetBSD: Makefile,v 1.16 2016/10/28 09:46:49 wiz Exp $

DISTNAME=	List-AllUtils-0.12
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-AllUtils/
COMMENT=	Combines List::Util and List::SomeUtils
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-SomeUtils>=0.28:../../devel/p5-List-SomeUtils
DEPENDS+=	p5-List-UtilsBy>=0.10:../../devel/p5-List-UtilsBy
DEPENDS+=	p5-Scalar-List-Utils>=1.31:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=	auto/List/AllUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
