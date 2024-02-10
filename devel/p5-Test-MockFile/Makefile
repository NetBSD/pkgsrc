# $NetBSD: Makefile,v 1.1 2024/02/10 01:15:15 schmonz Exp $

DISTNAME=		Test-MockFile-0.036
PKGNAME=		p5-${DISTNAME}
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
