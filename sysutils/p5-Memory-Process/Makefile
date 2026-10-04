# $NetBSD: Makefile,v 1.1 2026/10/04 09:54:58 wiz Exp $

DISTNAME=	Memory-Process-0.06
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	sysutils
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/S/SK/SKIM/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Memory::Process
COMMENT=	Perl class to determine actual memory usage
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Memory-Usage-[0-9]*:../../sysutils/p5-Memory-Usage
DEPENDS+=	p5-Readonly-[0-9]*:../../devel/p5-Readonly
TEST_DEPENDS+=	p5-Capture-Tiny-[0-9]*:../../devel/p5-Capture-Tiny
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

PERL5_PACKLIST=	auto/Memory/Process/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
