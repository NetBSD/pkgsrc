# $NetBSD: Makefile,v 1.43 2022/06/28 11:36:37 wiz Exp $

DISTNAME=	Text-Xslate-v3.5.8
PKGNAME=	p5-${DISTNAME:S/-v/-/}
PKGREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKAJI/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Text-Xslate
COMMENT=	Scalable template engine for Perl5
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Data-MessagePack>=0.38:../../devel/p5-Data-MessagePack
DEPENDS+=	p5-Mouse>=2.5.0:../../devel/p5-Mouse

TEST_DEPENDS+=	p5-File-Copy-Recursive-[0-9]*:../../sysutils/p5-File-Copy-Recursive
TEST_DEPENDS+=	p5-Module-Build-XSUtil-[0-9]*:../../devel/p5-Module-Build-XSUtil
TEST_DEPENDS+=	p5-Test-Requires>=0:../../devel/p5-Test-Requires
TEST_DEPENDS+=	p5-Test-LeakTrace>=0:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=		auto/Text/Xslate/.packlist
PERL5_MODULE_TYPE=	Module::Build

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
