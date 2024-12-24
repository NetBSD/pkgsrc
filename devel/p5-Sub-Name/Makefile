# $NetBSD: Makefile,v 1.32 2024/12/24 10:59:25 wiz Exp $

DISTNAME=	Sub-Name-0.28
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Sub/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Sub-Name
COMMENT=	Perl 5 module to (re)name a sub
LICENSE=	${PERL5_LICENSE}

TEST_DEPENDS+=	p5-Devel-CheckBin-[0-9]*:../../devel/p5-Devel-CheckBin

PERL5_PACKLIST=	auto/Sub/Name/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
