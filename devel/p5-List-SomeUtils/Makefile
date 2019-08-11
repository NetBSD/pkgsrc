# $NetBSD: Makefile,v 1.9 2019/08/11 13:19:43 wiz Exp $

DISTNAME=	List-SomeUtils-0.56
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=List/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/List-SomeUtils
COMMENT=	Provide the stuff missing in List::Util
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-SomeUtils-XS>=0.50:../../devel/p5-List-SomeUtils-XS
DEPENDS+=	p5-Module-Implementation-[0-9]*:../../devel/p5-Module-Implementation
BUILD_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=	auto/List/SomeUtils/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
