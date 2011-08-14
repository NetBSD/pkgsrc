# $NetBSD: Makefile,v 1.8 2011/08/14 12:26:29 obache Exp $
#

DISTNAME=	Parse-Method-Signatures-1.003013
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Parse/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Parse-Method-Signatures/
COMMENT=	Perl 5 module providing Perl 6 like method signature parser
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-List-MoreUtils>=0.20:../../devel/p5-List-MoreUtils
DEPENDS+=	p5-Moose-[0-9]*:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Traits>=0.06:../../devel/p5-MooseX-Traits
DEPENDS+=	p5-MooseX-Types>=0.17:../../devel/p5-MooseX-Types
DEPENDS+=	p5-MooseX-Types-Structured-[0-9]*:../../devel/p5-MooseX-Types-Structured
DEPENDS+=	p5-PPI>=1.203:../../devel/p5-PPI
DEPENDS+=	p5-namespace-clean>=0.10:../../devel/p5-namespace-clean

# For test target
BUILD_DEPENDS+=	p5-Test-Differences-[0-9]*:../../devel/p5-Test-Differences
BUILD_DEPENDS+=	p5-Test-Exception-[0-9]*:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-aliased-[0-9]*:../../devel/p5-aliased

PKG_DESTDIR_SUPPORT=	user-destdir

USE_LANGUAGES=	# empty
PERL5_MODULE_TYPE=	Module::Install
PERL5_PACKLIST=	auto/Parse/Method/Signatures/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
