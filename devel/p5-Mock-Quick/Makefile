# $NetBSD: Makefile,v 1.3 2022/06/28 11:32:44 wiz Exp $

DISTNAME=	Mock-Quick-1.111
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/EX/EXODIST/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Mock::Quick
COMMENT=	Quickly mock objects and classes, even temporarily replace them
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Exporter-Declare-[0-9]*:../../devel/p5-Exporter-Declare
TEST_DEPENDS+=	p5-Fennec-Lite-[0-9]*:../../devel/p5-Fennec-Lite
TEST_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception

PERL5_PACKLIST=		auto/Mock/Quick/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
