# $NetBSD: Makefile,v 1.17 2022/06/28 11:33:21 wiz Exp $
#

DISTNAME=	Test-Approx-0.03
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	12
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Approx
COMMENT=	Perl module for testing approximate equality of values
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Text-LevenshteinXS>=0.03:../../textproc/p5-Text-LevenshteinXS

PERL5_PACKLIST=		auto/Test/Approx/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
