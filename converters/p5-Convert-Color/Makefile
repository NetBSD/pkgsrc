# $NetBSD: Makefile,v 1.15 2019/06/30 20:14:15 nia Exp $

DISTNAME=	Convert-Color-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	4
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Convert-Color
COMMENT=	Color space conversions and named lookups
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-UtilsBy-[0-9]*:../../devel/p5-List-UtilsBy
DEPENDS+=	p5-Module-Pluggable-[0-9]*:../../devel/p5-Module-Pluggable

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Convert/Color/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
