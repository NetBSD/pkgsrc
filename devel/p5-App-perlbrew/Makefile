# $NetBSD: Makefile,v 1.27 2017/06/05 14:22:35 ryoon Exp $

DISTNAME=	App-perlbrew-0.78
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-perlbrew/
COMMENT=	Manage perl installations in your $$HOME
LICENSE=	mit

DEPENDS+=	p5-File-Path-Tiny>=0.1:../../devel/p5-File-Path-Tiny
DEPENDS+=	p5-Devel-PatchPerl>=0.86:../../devel/p5-Devel-PatchPerl
DEPENDS+=	p5-local-lib>=1.8.10:../../devel/p5-local-lib
DEPENDS+=	p5-Capture-Tiny>=0.22:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-CPAN-Perl-Releases>=1.10:../../devel/p5-CPAN-Perl-Releases
DEPENDS+=	curl-[0-9]*:../../www/curl

# actually, only TEST_DEPENDS
#BUILD_DEPENDS+=	{perl>=5.13.11,p5-Test-Simple>=0.98}:../../devel/p5-Test-Simple
#		Test::More in perl 5.14
BUILD_DEPENDS+=	p5-Test-Output>=0:../../devel/p5-Test-Output
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Spec>=0:../../devel/p5-Test-Spec
BUILD_DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
BUILD_DEPENDS+=	p5-IO-All>=0.46:../../devel/p5-IO-All
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings
#		File::Temp in perl 5.14

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/App/perlbrew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
