# $NetBSD: Makefile,v 1.24 2024/09/15 06:13:52 wiz Exp $

DISTNAME=	Convert-Color-0.18
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-Color
COMMENT=	Color space conversions and named lookups
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-UtilsBy-[0-9]*:../../devel/p5-List-UtilsBy
DEPENDS+=	p5-meta-[0-9]*:../../devel/p5-meta
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	p5-Test-Pod-[0-9]*:../../devel/p5-Test-Pod

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Convert/Color/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
