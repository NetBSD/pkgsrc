# $NetBSD: Makefile,v 1.10 2018/08/21 09:54:04 wiz Exp $

DISTNAME=	Alien-Build-1.48
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	textproc perl5
MASTER_SITES=	http://search.cpan.org/CPAN/authors/id/P/PL/PLICEASE/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~plicease/Alien-Build/
COMMENT=	Build external dependencies for use in CPAN
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=         auto/Alien/Build/.packlist

USE_TOOLS+=	pkg-config:run

DEPENDS+=	p5-Capture-Tiny>=0.17:../../devel/p5-Capture-Tiny
DEPENDS+=	p5-File-chdir-[0-9]*:../../devel/p5-File-chdir
DEPENDS+=	p5-File-Which>=1.10:../../devel/p5-File-Which
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
DEPENDS+=	p5-Test2-Suite-[0-9]*:../../devel/p5-Test2-Suite
DEPENDS+=	p5-FFI-CheckLib-[0-9]*:../../devel/p5-FFI-CheckLib
DEPENDS+=	p5-HTML-LinkExtractor-[0-9]*:../../www/p5-HTML-LinkExtractor

BUILD_DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
BUILD_DEPENDS+=	p5-Sort-Versions-[0-9]*:../../devel/p5-Sort-Versions
BUILD_DEPENDS+=	p5-Test2-Suite>=0.000060:../../devel/p5-Test2-Suite

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
