# $NetBSD: Makefile,v 1.36 2018/08/22 09:44:46 wiz Exp $

DISTNAME=		Test-Inline-2.213
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		5
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Inline/
COMMENT=		Inlining your tests next to the code being tested
LICENSE=		${PERL5_LICENSE}

BUILD_DEPENDS+=		p5-Test-ClassAPI>=1.02:../../devel/p5-Test-ClassAPI
BUILD_DEPENDS+=		p5-Test-Script>=1.02:../../devel/p5-Test-Script

DEPENDS+=		p5-Algorithm-Dependency>=1.02:../../devel/p5-Algorithm-Dependency
DEPENDS+=		p5-Class-Autouse>=1.29:../../devel/p5-Class-Autouse
DEPENDS+=		p5-Config-Tiny>=2.00:../../devel/p5-Config-Tiny
DEPENDS+=		p5-File-Find-Rule>=0.26:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Flat>=1.00:../../devel/p5-File-Flat
DEPENDS+=		p5-File-Remove>=0.37:../../sysutils/p5-File-Remove
DEPENDS+=		p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp
DEPENDS+=		p5-File-chmod>=0.31:../../sysutils/p5-File-chmod
DEPENDS+=		p5-Params-Util>=0.21:../../devel/p5-Params-Util
DEPENDS+=		p5-Pod-Tests>=0.18:../../textproc/p5-Pod-Tests

PERL5_PACKLIST=		auto/Test/Inline/.packlist
PERL5_MODULE_TYPE=	Module::Install::Bundled

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
