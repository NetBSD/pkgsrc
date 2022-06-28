# $NetBSD: Makefile,v 1.20 2022/06/28 11:32:51 wiz Exp $
#

DISTNAME=	Moose-Policy-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DR/DROLSKY/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Moose-Policy
COMMENT=	Moose-mounted police
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Moose/Policy/.packlist
PERL5_MODULE_TYPE=	Module::Build

DEPENDS+=	p5-Moose>=0.84:../../devel/p5-Moose
# for make test
BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
