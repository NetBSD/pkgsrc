# $NetBSD: Makefile,v 1.10 2019/08/11 13:19:56 wiz Exp $
#

DISTNAME=	MooseX-Attribute-Chained-1.0.3
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-Attribute-Chained
COMMENT=	Attribute that returns the instance to allow for chaining
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build

PERL5_PACKLIST=		auto/MooseX/Attribute/Chained/.packlist

DEPENDS+=		p5-Moose>=0:../../devel/p5-Moose
DEPENDS+=		p5-Try-Tiny>=0:../../devel/p5-Try-Tiny
# for make test
BUILD_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
