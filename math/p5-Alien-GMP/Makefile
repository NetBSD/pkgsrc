# $NetBSD: Makefile,v 1.1 2018/05/02 13:00:07 wiz Exp $

DISTNAME=	Alien-GMP-1.10
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~plicease/Alien-GMP/
COMMENT=	Alien package for the GNU Multiple Precision library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
BUILD_DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib
DEPENDS+=	p5-Alien-Role-Alt-[0-9]*:../../devel/p5-Alien-Role-Alt

USE_LANGUAGES=		c

#PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Alien/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
