# $NetBSD: Makefile,v 1.26 2022/06/28 11:33:30 wiz Exp $

DISTNAME=	Test-TempDir-0.11
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Test-TempDir
COMMENT=	Temporary files support for testing
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-File-NFSLock>=0:../../devel/p5-File-NFSLock
DEPENDS+=	p5-Moose>=0.87:../../devel/p5-Moose
DEPENDS+=	p5-MooseX-Types-Path-Class>=0:../../devel/p5-MooseX-Types-Path-Class
DEPENDS+=	p5-Path-Class>=0:../../devel/p5-Path-Class
DEPENDS+=	p5-Sub-Exporter>=0:../../devel/p5-Sub-Exporter
DEPENDS+=	p5-namespace-clean>=0.08:../../devel/p5-namespace-clean
TEST_DEPENDS+=	p5-Test-Requires-[0-9]*:../../devel/p5-Test-Requires

USE_LANGUAGES=	# empty

PERL5_PACKLIST=		auto/Test/TempDir/.packlist
PERL5_MODULE_TYPE=	Module::Build::Tiny

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
