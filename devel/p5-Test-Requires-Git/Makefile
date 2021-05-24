# $NetBSD: Makefile,v 1.15 2021/05/24 19:51:49 wiz Exp $

DISTNAME=	Test-Requires-Git-1.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	5
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BO/BOOK/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Test::Requires::Git
COMMENT=	Check your test requirements against the available version of Git
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Git-Version-Compare-[0-9]*:../../devel/p5-Git-Version-Compare
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=		auto/Test/Requires/Git/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
