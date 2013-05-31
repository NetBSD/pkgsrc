# $NetBSD: Makefile,v 1.8 2013/05/31 12:40:37 wiz Exp $

DISTNAME=	Package-DeprecationManager-0.13
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Package/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Package-DeprecationManager/
COMMENT=	Perl 5 module to manage deprecation warnings
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Package/DeprecationManager/.packlist

BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	p5-Test-Warn-[0-9]*:../../devel/p5-Test-Warn
BUILD_DEPENDS+=	p5-Test-Fatal-[0-9]*:../../devel/p5-Test-Fatal
BUILD_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires
DEPENDS+=	p5-Params-Util-[0-9]*:../../devel/p5-Params-Util
DEPENDS+=	p5-Sub-Install-[0-9]*:../../devel/p5-Sub-Install
DEPENDS+=	p5-List-MoreUtils-[0-9]*:../../devel/p5-List-MoreUtils

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
