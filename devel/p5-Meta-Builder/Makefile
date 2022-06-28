# $NetBSD: Makefile,v 1.3 2022/06/28 11:32:43 wiz Exp $

DISTNAME=	Meta-Builder-0.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Meta::Builder
COMMENT=	Tools for creating Meta objects to track custom metrics
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Fennec-Lite-[0-9]*:../../devel/p5-Fennec-Lite
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Meta/Builder/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
