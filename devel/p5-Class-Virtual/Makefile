# $NetBSD: Makefile,v 1.21 2023/07/06 09:38:49 wiz Exp $

DISTNAME=	Class-Virtual-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Class-Virtual
COMMENT=	Base class for virtual base classes
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert
TOOL_DEPENDS+=	p5-Class-Data-Inheritable-[0-9]*:../../devel/p5-Class-Data-Inheritable
TOOL_DEPENDS+=	p5-Class-ISA-[0-9]*:../../devel/p5-Class-ISA

PERL5_PACKLIST=		auto/Class/Virtual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
