# $NetBSD: Makefile,v 1.10 2019/08/11 13:20:36 wiz Exp $

DISTNAME=	Test-Requires-Git-1.008
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	https://cpan.metacpan.org/authors/id/B/BO/BOOK/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://cpan.metacpan.org/authors/id/B/BO/BOOK/
COMMENT=	Check your test requirements against the available version of Git
LICENSE=	${PERL5_LICENSE}

# for make test
BUILD_DEPENDS+=	p5-Git-Version-Compare-[0-9]*:../../devel/p5-Git-Version-Compare
BUILD_DEPENDS+=	p5-namespace-clean-[0-9]*:../../devel/p5-namespace-clean

PERL5_PACKLIST=         auto/Test/Requires/Git/.packlist
USE_LANGUAGES=          # none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
