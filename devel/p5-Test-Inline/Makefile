# $NetBSD: Makefile,v 1.17 2008/02/06 15:26:59 rhaen Exp $

DISTNAME=		Test-Inline-2.208
PKGNAME=		p5-${DISTNAME}
SVR4_PKGNAME=		p5tin
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		rhaen@NetBSD.org
HOMEPAGE=		http://search.cpan.org/dist/Test-Inline/
COMMENT=		Inlining your tests next to the code being tested

PKG_DESTDIR_SUPPORT=	user-destdir

BUILD_DEPENDS+=		p5-ExtUtils-AutoInstall>=0.49:../../devel/p5-ExtUtils-AutoInstall
DEPENDS+=		p5-Test-Script>=1.02:../../devel/p5-Test-Script
DEPENDS+=		p5-Algorithm-Dependency>=1.02:../../devel/p5-Algorithm-Dependency
DEPENDS+=		p5-Class-Autouse>=1.15:../../devel/p5-Class-Autouse
DEPENDS+=		p5-Config-Tiny>=2.00:../../devel/p5-Config-Tiny
DEPENDS+=		p5-File-Find-Rule>=0.26:../../devel/p5-File-Find-Rule
DEPENDS+=		p5-File-Flat>=0.95:../../devel/p5-File-Flat
DEPENDS+=		p5-File-Slurp>=9999.04:../../devel/p5-File-Slurp
DEPENDS+=		p5-File-chmod>=0.31:../../sysutils/p5-File-chmod
DEPENDS+=		p5-Params-Util>=0.05:../../devel/p5-Params-Util
DEPENDS+=		p5-Test-Simple>=0.33:../../devel/p5-Test-Simple
DEPENDS+=		p5-Pod-Tests>=0.18:../../textproc/p5-Pod-Tests

PERL5_PACKLIST=		auto/Test/Inline/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
