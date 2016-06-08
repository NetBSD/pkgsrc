# $NetBSD: Makefile,v 1.14 2016/06/08 19:23:06 wiz Exp $

DISTNAME=	List-AllUtils-0.10
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/List-AllUtils/
COMMENT=	Combines List::Util and List::SomeUtils
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-SomeUtils>=0.28:../../devel/p5-List-SomeUtils
DEPENDS+=	p5-Scalar-List-Utils>=1.31:../../devel/p5-Scalar-List-Utils
BUILD_DEPENDS+=	p5-Test-Warnings-[0-9]*:../../devel/p5-Test-Warnings

PERL5_PACKLIST=	auto/List/AllUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
