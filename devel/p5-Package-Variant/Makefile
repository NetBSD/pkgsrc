# $NetBSD: Makefile,v 1.18 2023/07/06 09:39:48 wiz Exp $
#

DISTNAME=	Package-Variant-1.003002
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Package-Variant
COMMENT=	Perl5 module wrapper for parameterizable packages
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Import-Into>=1.0:../../devel/p5-Import-Into
DEPENDS+=	p5-Module-Runtime>=0.13:../../devel/p5-Module-Runtime
DEPENDS+=	p5-strictures>=1.0:../../devel/p5-strictures

TOOL_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal

PERL5_PACKLIST=	auto/Package/Variant/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
