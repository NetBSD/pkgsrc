# $NetBSD: Makefile,v 1.21 2022/06/28 11:32:44 wiz Exp $

DISTNAME=	Method-Signatures-20170211
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BA/BAREFOOT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Method-Signatures
COMMENT=	Method and function declarations with signatures and no source filter
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose>=0.11:../../devel/p5-Any-Moose
DEPENDS+=	p5-Const-Fast>=0.006:../../devel/p5-Const-Fast
# would be used, but is currently broken
#DEPENDS+=	p5-Data-Alias>=1.08:../../devel/p5-Data-Alias
DEPENDS+=	p5-Devel-Declare>=0.006002:../../devel/p5-Devel-Declare
DEPENDS+=	p5-PPI>=1.203:../../devel/p5-PPI
DEPENDS+=	p5-Mouse>=0.64:../../devel/p5-Mouse
DEPENDS+=	p5-Sub-Name>=0.03:../../devel/p5-Sub-Name
DEPENDS+=	p5-Lexical-SealRequireHints>=0.007:../../devel/p5-Lexical-SealRequireHints

BUILD_DEPENDS+=	p5-Test-Exception>=0.29:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn>=0.10:../../devel/p5-Test-Warn

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Method/Signatures/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
