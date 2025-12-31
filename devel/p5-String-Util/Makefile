# $NetBSD: Makefile,v 1.16 2025/12/31 23:26:22 wen Exp $

DISTNAME=	String-Util-1.35
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/B/BA/BAKERSCOT/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/String::Util
COMMENT=	String processing utilities
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Test-Toolbox-[0-9]*:../../devel/p5-Test-Toolbox

PERL5_PACKLIST=		auto/String/Util/.packlist
USE_LANGUAGES=		# none

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
