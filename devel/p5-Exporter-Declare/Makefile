# $NetBSD: Makefile,v 1.4 2023/07/06 09:39:06 wiz Exp $

DISTNAME=	Exporter-Declare-0.114
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Exporter/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Exporter::Declare
COMMENT=	Exporting done right
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased
DEPENDS+=	p5-Meta-Builder-[0-9]*:../../devel/p5-Meta-Builder
TEST_DEPENDS+=	p5-Fennec-Lite-[0-9]*:../../devel/p5-Fennec-Lite
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Exporter/Declare/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
