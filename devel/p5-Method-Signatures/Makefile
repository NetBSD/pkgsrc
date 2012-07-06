# $NetBSD: Makefile,v 1.2 2012/07/06 11:01:06 sno Exp $

DISTNAME=	Method-Signatures-20120523
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BA/BAREFOOT/}
#MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Method/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Method-Signatures/
COMMENT=	Method and function declarations with signatures and no source filter
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Any-Moose>=0.11:../../devel/p5-Any-Moose
DEPENDS+=	p5-Const-Fast>=0.006:../../devel/p5-Const-Fast
DEPENDS+=	p5-Data-Alias>=1.08:../../devel/p5-Data-Alias
DEPENDS+=	p5-Devel-BeginLift>=0.001001:../../devel/p5-Devel-BeginLift
DEPENDS+=	p5-Devel-Declare>=0.006002:../../devel/p5-Devel-Declare
DEPENDS+=	p5-Devel-Pragma>=0.40:../../devel/p5-Devel-Pragma
DEPENDS+=	p5-PPI>=1.203:../../devel/p5-PPI
DEPENDS+=	p5-Mouse>=0.64:../../devel/p5-Mouse
DEPENDS+=	p5-Sub-Name>=0.03:../../devel/p5-Sub-Name

BUILD_DEPENDS+=	p5-Test-Exception>=0.29:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Warn>=0.10:../../devel/p5-Test-Warn

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Method/Signatures/.packlist
PERL5_MODULE_TYPE=	Module::Build

PKG_DESTDIR_SUPPORT=	user-destdir

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
