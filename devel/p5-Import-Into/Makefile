# $NetBSD: Makefile,v 1.18 2022/06/28 11:32:38 wiz Exp $

DISTNAME=	Import-Into-1.002005
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	7
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/H/HA/HAARG/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Import-Into
COMMENT=	Perl5 module to import packages into other packages
LICENSE=	${PERL5_LICENSE}

# Add for 'make test', as a interim solution
BUILD_DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime

PERL5_PACKLIST=	auto/Import/Into/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
