# $NetBSD: Makefile,v 1.24 2020/03/21 12:22:48 mef Exp $

DISTNAME=	Alien-Build-2.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/P/PL/PLICEASE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-Build
COMMENT=	Build external dependencies for use in CPAN
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Alien/Build/.packlist

USE_TOOLS+=	pkg-config:run

DEPENDS+=	p5-Capture-Tiny>=0.17:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-File-Which>=1.10:../../devel/p5-File-Which
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
DEPENDS+=	p5-FFI-CheckLib-[0-9]*:../../devel/p5-FFI-CheckLib
DEPENDS+=	p5-HTML-LinkExtractor-[0-9]*:../../www/p5-HTML-LinkExtractor

TEST_DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
TEST_DEPENDS+=	p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
TEST_DEPENDS+=	p5-Test2-Suite>=0.000060:../../devel/p5-Test2-Suite
TEST_DEPENDS+=	p5-Alien-Base-ModuleBuild-[0-9]*:../../devel/p5-Alien-Base-ModuleBuild

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
