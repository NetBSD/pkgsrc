# $NetBSD: Makefile,v 1.26 2022/06/28 11:32:55 wiz Exp $
#

DISTNAME=	MooseX-StrictConstructor-0.21
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	6
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=MooseX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MooseX-StrictConstructor
COMMENT=	Make your object constructors blow up on unknown attributes
LICENSE=	artistic-2.0

DEPENDS+=	p5-Moose>=0.94:../../devel/p5-Moose

#BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=		p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=		p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/MooseX/StrictConstructor/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
