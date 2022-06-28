# $NetBSD: Makefile,v 1.2 2022/06/28 11:33:38 wiz Exp $

DISTNAME=	constant-defer-6
PKGNAME=	p5-${DISTNAME}
PKGREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN:=../../authors/id/K/KR/KRYDE/}

MAINTAINER=	pkgsrc-users@NetBSD.org
HOMEPAGE=	https://metacpan.org/release/constant-defer
COMMENT=	constant subs with deferred value calculation
LICENSE=	gnu-gpl-v3

PERL5_PACKLIST=		auto/constant/defer/.packlist

.include "../../lang/perl5/module.mk"
.include "../../mk/bsd.pkg.mk"
