# $NetBSD: Makefile,v 1.18 2022/06/28 11:31:51 wiz Exp $

DISTNAME=	Alien-Base-ModuleBuild-1.15
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/P/PL/PLICEASE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Alien-Base-ModuleBuild
COMMENT=	Module::Build subclass for building Alien:: modules and libraries
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=		auto/Alien/Base/ModuleBuild/.packlist
PERL5_MODULE_TYPE=	Module::Build

USE_TOOLS+=	pkg-config:run

DEPENDS+=	p5-Alien-Build>=1.22:../../devel/p5-Alien-Build
DEPENDS+=	p5-Archive-Extract-[0-9]*:../../archivers/p5-Archive-Extract
DEPENDS+=	p5-Capture-Tiny>=0.17:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-HTML-LinkExtractor-[0-9]*:../../www/p5-HTML-LinkExtractor
DEPENDS+=	p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
DEPENDS+=	p5-Shell-Config-Generate-[0-9]*:../../devel/p5-Shell-Config-Generate
DEPENDS+=	p5-Shell-Guess-[0-9]*:../../devel/p5-Shell-Guess

# TEST_DEPENDS
TEST_DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
