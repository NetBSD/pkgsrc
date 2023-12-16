# $NetBSD: Makefile,v 1.15 2023/12/16 11:53:46 mef Exp $

DISTNAME=	Git-Version-Compare-1.005
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Git-Version-Compare
COMMENT=	Functions to compare Git versions
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
TEST_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/Version/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
