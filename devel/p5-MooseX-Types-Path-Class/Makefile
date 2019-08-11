# $NetBSD: Makefile,v 1.23 2019/08/11 13:20:01 wiz Exp $

DISTNAME=	MooseX-Types-Path-Class-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Types-Path-Class
COMMENT=	Path::Class type library for Moose
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moose>=2:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types>=0.04:../../devel/p5-MooseX-Types
DEPENDS+=	p5-Path-Class>=0.16:../../devel/p5-Path-Class

# For tests (but introduce a circular dependency for devel/p5-MooseX-Getopt)
#BUILD_DEPENDS+=	p5-MooseX-Getopt>=0:../../devel/p5-MooseX-Getopt
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager
BUILD_DEPENDS+=	p5-Test-Needs>=0:../../devel/p5-Test-Needs

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/Types/Path/Class/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
