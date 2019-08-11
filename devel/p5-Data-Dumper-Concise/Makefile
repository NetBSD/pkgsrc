# $NetBSD: Makefile,v 1.18 2019/08/11 13:19:09 wiz Exp $

DISTNAME=	Data-Dumper-Concise-2.023
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Data/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Data-Dumper-Concise
COMMENT=	Perl 5 module to dump references with concision and deparsing
LICENSE=	${PERL5_LICENSE}

# XXX recommended: Devel::ArgNames - import

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Data/Dumper/Concise/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
