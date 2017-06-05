# $NetBSD: Makefile,v 1.11 2017/06/05 14:23:25 ryoon Exp $
#

DISTNAME=	PPI-PowerToys-0.14
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	8
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=PPI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/PPI-PowerToys/
COMMENT=	Handy collection of small PPI-based utilities
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-Find-Rule>=0.30:../../devel/p5-File-Find-Rule
DEPENDS+=	p5-File-Find-Rule-Perl>=0.03:../../devel/p5-File-Find-Rule-Perl
DEPENDS+=	p5-PPI>=1.201:../../devel/p5-PPI
#DEPENDS+=	{perl>=5.10.1,p5-version>=0.7400}:../../devel/p5-version

BUILD_DEPENDS+=	p5-IPC-Run3>=0.034:../../devel/p5-IPC-Run3
BUILD_DEPENDS+=	p5-Probe-Perl>=0.01:../../devel/p5-Probe-Perl
BUILD_DEPENDS+=	p5-Test-Script>=1.03:../../devel/p5-Test-Script

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/PPI/PowerToys/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
