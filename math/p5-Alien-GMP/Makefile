# $NetBSD: Makefile,v 1.12 2023/07/06 09:40:51 wiz Exp $

DISTNAME=	Alien-GMP-1.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Alien/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-GMP
COMMENT=	Alien package for the GNU Multiple Precision library
LICENSE=	gnu-lgpl-v3

DEPENDS+=	p5-Alien-Build-[0-9]*:../../devel/p5-Alien-Build
TOOL_DEPENDS+=	p5-Devel-CheckLib-[0-9]*:../../devel/p5-Devel-CheckLib

USE_LANGUAGES=		c
PERL5_PACKLIST=		auto/Alien/GMP/.packlist

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
