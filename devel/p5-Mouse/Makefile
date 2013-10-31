# $NetBSD: Makefile,v 1.40 2013/10/31 00:57:11 wen Exp $

DISTNAME=	Mouse-1.13
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/G/GF/GFUJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/Mouse/
COMMENT=	Perl module implementing an extension of the perl object system
LICENSE=	${PERL5_LICENSE}

BUILD_DEPENDS+=	p5-Test-Requires>=0.06:../../devel/p5-Test-Requires
BUILD_DEPENDS+=	{perl>=5.10.1,p5-Test-Simple>=0.88}:../../devel/p5-Test-Simple
BUILD_DEPENDS+=	{perl>=5.14.1,p5-ExtUtils-ParseXS>=2.21}:../../devel/p5-ExtUtils-ParseXS
BUILD_DEPENDS+=	p5-Devel-PPPort>=3.19:../../devel/p5-Devel-PPPort

MAKE_JOBS_SAFE=	no

PERL5_PACKLIST=	auto/Mouse/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
