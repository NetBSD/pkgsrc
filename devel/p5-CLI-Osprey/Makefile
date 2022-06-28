# $NetBSD: Makefile,v 1.4 2022/06/28 11:31:56 wiz Exp $

DISTNAME=	CLI-Osprey-0.08
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=CLI/}

MAINTAINER=	wen@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/CLI-Osprey
COMMENT=	MooX::Options + MooX::Cmd + Sanity
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Moo-[0-9]*:../../devel/p5-Moo
DEPENDS+=	p5-Getopt-Long-Descriptive-[0-9]*:../../devel/p5-Getopt-Long-Descriptive
DEPENDS+=	p5-Path-Tiny-[0-9]*:../../filesystems/p5-Path-Tiny
TEST_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
TEST_DEPENDS+=	p5-Test-Lib-[0-9]*:../../devel/p5-Test-Lib

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/CLI/Osprey/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
