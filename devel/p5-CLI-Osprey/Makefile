# $NetBSD: Makefile,v 1.1 2021/04/19 01:53:38 wen Exp $

DISTNAME=	CLI-Osprey-0.08
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CLI/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CLI-Osprey
COMMENT=	MooX::Options + MooX::Cmd + Sanity
LICENSE=	${PERL5_LICENSE}

# TEST_DEPENDS
TEST_DEPENDS=	p5-Test-Lib>=0:../../devel/p5-Test-Lib

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CLI/Osprey/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
