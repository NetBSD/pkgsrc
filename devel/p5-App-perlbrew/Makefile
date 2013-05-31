# $NetBSD: Makefile,v 1.12 2013/05/31 12:40:03 wiz Exp $

DISTNAME=	App-perlbrew-0.54
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=App/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/dist/App-perlbrew/
COMMENT=	Manage perl installations in your $$HOME
LICENSE=	mit

DEPENDS+=	p5-File-Path-Tiny>=0.1:../../devel/p5-File-Path-Tiny
DEPENDS+=	p5-Devel-PatchPerl>=0.76:../../devel/p5-Devel-PatchPerl
DEPENDS+=	p5-local-lib>=1.008:../../devel/p5-local-lib
DEPENDS+=	p5-Capture-Tiny>=0.20:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-CPAN-Perl-Releases>=0.76:../../devel/p5-CPAN-Perl-Releases

# actually, only TEST_DEPENDS
BUILD_DEPENDS+=	p5-Test-Simple>=0.98:../../devel/p5-Test-Simple
#		Test::More in perl 5.14
BUILD_DEPENDS+=	p5-Test-Output>=0:../../devel/p5-Test-Output
BUILD_DEPENDS+=	p5-Test-Exception>=0:../../devel/p5-Test-Exception
BUILD_DEPENDS+=	p5-Test-Spec>=0:../../devel/p5-Test-Spec
BUILD_DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
BUILD_DEPENDS+=	p5-IO-All>=0:../../devel/p5-IO-All
#		File::Temp in perl 5.14

USE_LANGUAGES=		# empty
USE_TOOLS+=		perl
PERL5_PACKLIST=		auto/App/perlbrew/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
