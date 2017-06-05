# $NetBSD: Makefile,v 1.13 2017/06/05 14:22:44 ryoon Exp $

DISTNAME=	Class-Virtual-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Virtual/
COMMENT=	Base class for virtual base classes
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
BUILD_DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
BUILD_DEPENDS+=	p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA

PERL5_PACKLIST=		auto/Class/Virtual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
