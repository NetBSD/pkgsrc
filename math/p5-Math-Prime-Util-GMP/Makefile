# $NetBSD: Makefile,v 1.2 2026/07/16 19:04:13 wiz Exp $

DISTNAME=	Math-Prime-Util-GMP-0.53
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
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
