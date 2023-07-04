# $NetBSD: Makefile,v 1.17 2023/07/04 12:15:59 wen Exp $

DISTNAME=	Algorithm-Permute-0.17
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=Algorithm/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Algorithm-Permute
COMMENT=	Perl module for generating permutations with object oriented interface
LICENSE=	${PERL5_LICENSE}

# for make test
TOOL_DEPENDS+=	p5-Test-LeakTrace-[0-9]*:../../devel/p5-Test-LeakTrace

PERL5_PACKLIST=		auto/Algorithm/Permute/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
