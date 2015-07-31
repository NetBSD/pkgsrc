# $NetBSD: Makefile,v 1.3 2015/07/31 14:12:00 bsiegert Exp $

DISTNAME=	Canary-Stability-2006
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../by-authors/id/M/ML/MLEHMANN/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	http://search.cpan.org/~mlehmann/${DISTNAME}/
COMMENT=	Canary to check Perl compatibility
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Canary/Stability/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
