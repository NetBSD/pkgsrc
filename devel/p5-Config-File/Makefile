# $NetBSD: Makefile,v 1.9 2020/09/08 13:16:35 wiz Exp $

DISTNAME=	Config-File-1.54
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/T/TH/THESEAL/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Config::File
COMMENT=	Parse a simple configuration file
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
TEST_DEPENDS+=	p5-Pod-Parser-[0-9]*:../../textproc/p5-Pod-Parser

PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Config/File/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
