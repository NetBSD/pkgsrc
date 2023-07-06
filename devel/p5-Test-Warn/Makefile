# $NetBSD: Makefile,v 1.35 2023/07/06 09:40:20 wiz Exp $

DISTNAME=		Test-Warn-0.37
PKGNAME=		p5-${DISTNAME}
PKGREVISION=		1
CATEGORIES=		devel perl5
MASTER_SITES=		${MASTER_SITE_PERL_CPAN:=Test/}

MAINTAINER=		pkgsrc-users@NetBSD.org
HOMEPAGE=		https://metacpan.org/release/Test-Warn
COMMENT=		Perl extension to test methods for warnings
LICENSE=		${PERL5_LICENSE}

DEPENDS+=		p5-Sub-Uplevel>=0.12:../../devel/p5-Sub-Uplevel

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Test/Warn/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
