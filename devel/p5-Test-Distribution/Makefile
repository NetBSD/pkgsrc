# $NetBSD: Makefile,v 1.18 2019/06/30 20:15:51 nia Exp $

DISTNAME=	Test-Distribution-2.00
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	11
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-Distribution
COMMENT=	Perl5 module testing all modules of a distribution

# In perl
#DEPENDS+=	{perl>=5.8.8,p5-ExtUtils-Manifest>=1.43}:../../devel/p5-ExtUtils-Manifest
#DEPENDS+=	{perl>=5.6.2,p5-Test-Simple>=0.45}:../../devel/p5-Test-Simple

DEPENDS+=	p5-File-Find-Rule>=0.03:../../devel/p5-File-Find-Rule
#DEPENDS+=	{perl>=5.16.0,p5-Module-CoreList>=1.93}:../../devel/p5-Module-CoreList
DEPENDS+=	p5-Test-Pod>=0.95:../../devel/p5-Test-Pod
DEPENDS+=	p5-Test-Pod-Coverage-[0-9]*:../../devel/p5-Test-Pod-Coverage
DEPENDS+=	p5-Pod-Coverage>=0.17:../../textproc/p5-Pod-Coverage

PERL5_PACKLIST=		auto/Test/Distribution/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
