# $NetBSD: Makefile,v 1.11 2019/10/10 11:34:12 mef Exp $

DISTNAME=	Canary-Stability-2013
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/MLEHMANN/${DISTNAME}
COMMENT=	Canary to check Perl compatibility
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Canary/Stability/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
