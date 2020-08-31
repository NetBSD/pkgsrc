# $NetBSD: Makefile,v 1.17 2020/08/31 18:07:40 wiz Exp $

DISTNAME=	Class-Virtual-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Virtual
COMMENT=	Base class for virtual base classes
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
BUILD_DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
BUILD_DEPENDS+=	p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA

PERL5_PACKLIST=		auto/Class/Virtual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
