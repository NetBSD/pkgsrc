# $NetBSD: Makefile,v 1.7 2026/07/16 19:01:49 wiz Exp $

DISTNAME=	Algorithm-Backoff-0.010
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	3
CATEGORIES=	devel perl5
MASTER_SITES=	https://cpan.metacpan.org/authors/id/P/PE/PERLANCAR/

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Backoff
COMMENT=	Various backoff strategies for retry
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Algorithm/Backoff/.packlist
USE_LANGUAGES=	# none

TEST_DEPENDS+=	p5-Test-Number-Delta-[0-9]*:../../math/p5-Test-Number-Delta

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
