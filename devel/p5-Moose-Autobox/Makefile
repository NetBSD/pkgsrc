# $NetBSD: Makefile,v 1.20 2019/06/30 20:15:23 nia Exp $
#

DISTNAME=	Moose-Autobox-0.16
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/E/ET/ETHER//}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Moose-Autobox
COMMENT=	Perl 5 module providing autoboxed wrappers for native datatypes
LICENSE=	${PERL5_LICENSE}

USE_LANGUAGES=	# empty
PERL5_PACKLIST=	auto/Moose/Autobox/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

DEPENDS+=	p5-autobox>=2.23:../../devel/p5-autobox
DEPENDS+=	p5-Moose>=0.42:../../devel/p5-Moose
DEPENDS+=	p5-Syntax-Keyword-Junction-[0-9]*:../../devel/p5-Syntax-Keyword-Junction
DEPENDS+=	p5-List-MoreUtils>=0.07:../../devel/p5-List-MoreUtils

BUILD_DEPENDS+=	p5-Test-Exception>=0.21:../../devel/p5-Test-Exception
# for make test
BUILD_DEPENDS+=p5-Package-DeprecationManager-[0-9]*:../../devel/p5-Package-DeprecationManager


.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
