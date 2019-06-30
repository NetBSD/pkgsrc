# $NetBSD: Makefile,v 1.8 2019/06/30 20:15:06 nia Exp $

DISTNAME=	Git-Version-Compare-1.004
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	2
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Git/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Git-Version-Compare
COMMENT=	Functions to compare Git versions
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean
BUILD_DEPENDS+=	p5-Test-NoWarnings-[0-9]*:../../devel/p5-Test-NoWarnings

USE_LANGUAGES=		# empty
PERL5_PACKLIST=		auto/Git/Version/Compare/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
