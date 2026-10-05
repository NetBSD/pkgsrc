# $NetBSD: Makefile,v 1.34 2026/10/05 13:29:46 wen Exp $

DISTNAME=	Module-Starter-1.82
PKGNAME=	p5-${DISTNAME}0
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/X/XS/XSAWYERX/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/Module-Starter
COMMENT=	Perl 5 module acting as a simple starter kit for any module
LICENSE=	${PERL5_LICENSE}

DEPENDS+=	p5-Module-Runtime-[0-9]*:../../devel/p5-Module-Runtime
DEPENDS+=	p5-Software-License-[0-9]*:../../devel/p5-Software-License

PERL5_PACKLIST=	auto/Module/Starter/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
