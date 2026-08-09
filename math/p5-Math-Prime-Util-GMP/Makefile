# $NetBSD: Makefile,v 1.3 2026/08/09 04:28:04 wiz Exp $

DISTNAME=	Math-Prime-Util-GMP-0.54
PKGNAME=	p5-${DISTNAME}
CATEGORIES=	math perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/D/DA/DANAJ/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/pod/Math::Prime::Util::GMP
COMMENT=	Perl5 Utilities related to prime numbers and factoring, using GMP
LICENSE=	${PERL5_LICENSE}

PERL5_PACKLIST=	auto/Math/Prime/Util/GMP/.packlist

USE_LANGUAGES+=	c

.include "../../devel/gmp/buildlink3.mk"
.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
