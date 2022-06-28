# $NetBSD: Makefile,v 1.43 2022/06/28 11:31:53 wiz Exp $

DISTNAME=	App-perlbrew-0.92
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/App-perlbrew
COMMENT=	Manage perl installations in your $$HOME
LICENSE=	mit

DEPENDS+=	p5-File-Path-Tiny>=0.1:../../devel/p5-File-Path-Tiny
DEPENDS+=	p5-File-Which-[0-9]*:../../devel/p5-File-Which
DEPENDS+=	p5-Devel-PatchPerl>=1.52:../../devel/p5-Devel-PatchPerl
DEPENDS+=	p5-local-lib>=2.000014:../../devel/p5-local-lib
DEPENDS+=	p5-Capture-Tiny>=0.36:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-CPAN-Perl-Releases>=3.66:../../devel/p5-CPAN-Perl-Releases
DEPENDS+=	curl-[0-9]*:../../www/curl

# actually, only TEST_DEPENDS
#TEST_DEPENDS+=	{perl>=5.19.6,p5-Test-Simple>=1.001002}:../../devel/p5-Test-Simple
TEST_DEPENDS+=	p5-Test-Output>=1.03:../../devel/p5-Test-Output
TEST_DEPENDS+=	p5-Test-Exception>=0.32:../../devel/p5-Test-Exception
TEST_DEPENDS+=	p5-Test-Spec>=0.47:../../devel/p5-Test-Spec
TEST_DEPENDS+=	p5-Path-Class>=0.33:../../devel/p5-Path-Class
TEST_DEPENDS+=	p5-IO-All>=0.51:../../devel/p5-IO-All
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
TEST_DEPENDS+=	p5-Test-TempDir-Tiny>=0:../../devel/p5-Test-TempDir-Tiny

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_MODULE_TYPE=	Module::Build::Tiny

PERL5_PACKLIST=		auto/App/perlbrew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
