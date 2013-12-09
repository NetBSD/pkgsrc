# $NetBSD: Makefile,v 1.6 2013/12/09 14:17:41 obache Exp $

DISTNAME=	Convert-Color-0.09
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	converters perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Convert/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Convert-Color/
COMMENT=	Color space conversions and named lookups
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-UtilsBy-[0-9]*:../../devel/p5-List-UtilsBy
DEPENDS+=	{perl>=5.8.9,p5-Module-Pluggable-[0-9]*}:../../devel/p5-Module-Pluggable

USE_LANGUAGES=		# empty
PERL5_MODULE_TYPE=	Module::Build
PERL5_PACKLIST=		auto/Convert/Color/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
