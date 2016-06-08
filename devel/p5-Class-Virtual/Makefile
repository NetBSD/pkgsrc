# $NetBSD: Makefile,v 1.11 2016/06/08 19:22:42 wiz Exp $

DISTNAME=	Class-Virtual-0.07
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Class/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Class-Virtual/
COMMENT=	Base class for virtual base classes
LICENSE=	${PERL5_LICENSE}

# necessary for test
#DEPENDS+=	p5-Carp-Assert-[0-9]*:../../devel/p5-Carp-Assert

PERL5_PACKLIST=		auto/Class/Virtual/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
