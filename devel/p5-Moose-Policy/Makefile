# $NetBSD: Makefile,v 1.13 2017/06/05 14:23:18 ryoon Exp $
#

DISTNAME=	Moose-Policy-0.05
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/D/DR/DROLSKY/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Moose-Policy/
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
