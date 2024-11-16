# $NetBSD: Makefile,v 1.2 2024/11/16 12:05:20 wiz Exp $

DISTNAME=		Test-MockFile-0.036
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

PERL5_PACKLIST=		auto/Test/MockFile/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
