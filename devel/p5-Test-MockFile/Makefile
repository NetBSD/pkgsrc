# $NetBSD: Makefile,v 1.5 2026/07/16 19:03:33 wiz Exp $

DISTNAME=		Test-MockFile-0.037
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/pod/Test::MockFile
COMMENT=		Validate file-interaction code that without touching the file system
LICENSE=		artistic-2.0

DEPENDS+=		p5-Overload-FileCheck>=0.013:../../devel/p5-Overload-FileCheck
DEPENDS+=		p5-Text-Glob>=0:../../textproc/p5-Text-Glob

TEST_DEPENDS+=		p5-Test2-Harness>=0:../../devel/p5-Test2-Harness \
			p5-Test2-Tools-Explain>=0:../../devel/p5-Test2-Tools-Explain \
			p5-Test2-Plugin-NoWarnings>=0:../../devel/p5-Test2-Plugin-NoWarnings \
			p5-File-Slurper>=0:../../devel/p5-File-Slurper

PERL5_PACKLIST=		auto/Test/MockFile/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
